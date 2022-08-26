/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "ecmascript/compiler/new_object_stub_builder.h"

#include "ecmascript/compiler/stub_builder-inl.h"
#include "ecmascript/global_env.h"
#include "ecmascript/global_env_constants.h"
#include "ecmascript/js_arguments.h"
#include "ecmascript/js_object.h"
#include "ecmascript/js_thread.h"
#include "ecmascript/lexical_env.h"
#include "ecmascript/mem/mem.h"

namespace panda::ecmascript::kungfu {
void NewObjectStubBuilder::NewLexicalEnv(Variable *result, Label *exit, GateRef numSlots, GateRef parent)
{
    auto env = GetEnvironment();

    auto length = Int32Add(numSlots, Int32(LexicalEnv::RESERVED_ENV_LENGTH));
    size_ = ComputeTaggedArraySize(ChangeInt32ToIntPtr(length));
    Label afterAllocate(env);
    // Be careful. NO GC is allowed when initization is not complete.
    AllocateInYoung(result, &afterAllocate);
    Bind(&afterAllocate);
    Label hasPendingException(env);
    Label noException(env);
    Branch(TaggedIsException(result->ReadVariable()), &hasPendingException, &noException);
    Bind(&noException);
    {
        auto hclass = GetGlobalConstantValue(
            VariableType::JS_POINTER(), glue_, ConstantIndex::ENV_CLASS_INDEX);
        StoreHClass(glue_, result->ReadVariable(), hclass);
        Label afterInitialize(env);
        InitializeTaggedArrayWithSpeicalValue(&afterInitialize,
            result->ReadVariable(), Hole(), Int32(LexicalEnv::RESERVED_ENV_LENGTH), length);
        Bind(&afterInitialize);
        SetValueToTaggedArray(VariableType::INT64(),
            glue_, result->ReadVariable(), Int32(LexicalEnv::SCOPE_INFO_INDEX), Hole());
        SetValueToTaggedArray(VariableType::JS_POINTER(),
            glue_, result->ReadVariable(), Int32(LexicalEnv::PARENT_ENV_INDEX), parent);
        Jump(exit);
    }
    Bind(&hasPendingException);
    {
        Jump(exit);
    }
}

void NewObjectStubBuilder::NewJSObject(Variable *result, Label *exit, GateRef hclass)
{
    auto env = GetEnvironment();

    size_ = GetObjectSizeFromHClass(hclass);
    Label afterAllocate(env);
    // Be careful. NO GC is allowed when initization is not complete.
    AllocateInYoung(result, &afterAllocate);
    Bind(&afterAllocate);
    Label hasPendingException(env);
    Label noException(env);
    Branch(TaggedIsException(result->ReadVariable()), &hasPendingException, &noException);
    Bind(&noException);
    {
        StoreHClass(glue_, result->ReadVariable(), hclass);
        Label afterInitialize(env);
        InitializeWithSpeicalValue(&afterInitialize,
            result->ReadVariable(), Undefined(), Int32(JSObject::SIZE), ChangeIntPtrToInt32(size_));
        Bind(&afterInitialize);
        auto emptyArray = GetGlobalConstantValue(
            VariableType::JS_POINTER(), glue_, ConstantIndex::EMPTY_ARRAY_OBJECT_INDEX);
        SetHash(glue_, result->ReadVariable(), Int64(JSTaggedValue(0).GetRawData()));
        SetPropertiesArray(VariableType::INT64(),
            glue_, result->ReadVariable(), emptyArray);
        SetElementsArray(VariableType::INT64(),
            glue_, result->ReadVariable(), emptyArray);
        Jump(exit);
    }
    Bind(&hasPendingException);
    {
        Jump(exit);
    }
}

void NewObjectStubBuilder::NewArgumentsList(Variable *result, Label *exit,
    GateRef sp, GateRef startIdx, GateRef numArgs)
{
    auto env = GetEnvironment();
    DEFVARIABLE(i, VariableType::INT32(), Int32(0));
    Label setHClass(env);
    size_ = ComputeTaggedArraySize(ChangeInt32ToIntPtr(numArgs));
    Label afterAllocate(env);
    AllocateInYoung(result, &afterAllocate);
    Bind(&afterAllocate);
    Branch(TaggedIsException(result->ReadVariable()), exit, &setHClass);
    Bind(&setHClass);
    GateRef arrayClass = GetGlobalConstantValue(VariableType::JS_POINTER(), glue_,
                                                ConstantIndex::ARRAY_CLASS_INDEX);
    StoreHClass(glue_, result->ReadVariable(), arrayClass);
    Store(VariableType::INT32(), glue_, result->ReadVariable(), IntPtr(TaggedArray::LENGTH_OFFSET), numArgs);
    // skip InitializeTaggedArrayWithSpeicalValue due to immediate setting arguments
    Label setArgumentsBegin(env);
    Label setArgumentsAgain(env);
    Label setArgumentsEnd(env);
    Branch(Int32UnsignedLessThan(*i, numArgs), &setArgumentsBegin, &setArgumentsEnd);
    LoopBegin(&setArgumentsBegin);
    GateRef idx = ChangeInt32ToIntPtr(Int32Add(startIdx, *i));
    GateRef argument = Load(VariableType::JS_ANY(), sp, PtrMul(IntPtr(sizeof(JSTaggedType)), idx));
    SetValueToTaggedArray(VariableType::JS_ANY(), glue_, result->ReadVariable(), *i, argument);
    i = Int32Add(*i, Int32(1));
    Branch(Int32UnsignedLessThan(*i, numArgs), &setArgumentsAgain, &setArgumentsEnd);
    Bind(&setArgumentsAgain);
    LoopEnd(&setArgumentsBegin);
    Bind(&setArgumentsEnd);
    Jump(exit);
}

void NewObjectStubBuilder::NewArgumentsObj(Variable *result, Label *exit,
    GateRef argumentsList, GateRef numArgs)
{
    auto env = GetEnvironment();

    GateRef glueGlobalEnvOffset = IntPtr(JSThread::GlueData::GetGlueGlobalEnvOffset(env->Is32Bit()));
    GateRef glueGlobalEnv = Load(VariableType::NATIVE_POINTER(), glue_, glueGlobalEnvOffset);
    GateRef argumentsClass = GetGlobalEnvValue(VariableType::JS_ANY(), glueGlobalEnv,
                                               GlobalEnv::ARGUMENTS_CLASS);
    Label afterNewObject(env);
    NewJSObject(result, &afterNewObject, argumentsClass);
    Bind(&afterNewObject);
    Label setArgumentsObjProperties(env);
    Branch(TaggedIsException(result->ReadVariable()), exit, &setArgumentsObjProperties);
    Bind(&setArgumentsObjProperties);
    SetPropertyInlinedProps(glue_, result->ReadVariable(), argumentsClass, IntToTaggedNGC(numArgs),
                            Int32(JSArguments::LENGTH_INLINE_PROPERTY_INDEX));
    SetElementsArray(VariableType::JS_ANY(), glue_, result->ReadVariable(), argumentsList);
    GateRef arrayProtoValuesFunction = GetGlobalEnvValue(VariableType::JS_ANY(), glueGlobalEnv,
                                                         GlobalEnv::ARRAY_PROTO_VALUES_FUNCTION_INDEX);
    SetPropertyInlinedProps(glue_, result->ReadVariable(), argumentsClass, arrayProtoValuesFunction,
                            Int32(JSArguments::ITERATOR_INLINE_PROPERTY_INDEX));
    GateRef accessorCaller = GetGlobalEnvValue(VariableType::JS_ANY(), glueGlobalEnv,
                                               GlobalEnv::ARGUMENTS_CALLER_ACCESSOR);
    SetPropertyInlinedProps(glue_, result->ReadVariable(), argumentsClass, accessorCaller,
                            Int32(JSArguments::CALLER_INLINE_PROPERTY_INDEX));
    GateRef accessorCallee = GetGlobalEnvValue(VariableType::JS_ANY(), glueGlobalEnv,
                                               GlobalEnv::ARGUMENTS_CALLEE_ACCESSOR);
    SetPropertyInlinedProps(glue_, result->ReadVariable(), argumentsClass, accessorCallee,
                            Int32(JSArguments::CALLEE_INLINE_PROPERTY_INDEX));
    Jump(exit);
}

void NewObjectStubBuilder::AllocateInYoung(Variable *result, Label *exit)
{
    auto env = GetEnvironment();
    Label success(env);
    Label callRuntime(env);

#ifdef ARK_ASAN_ON
    DEFVARIABLE(ret, VariableType::JS_ANY(), Undefined());
    Jump(&callRuntime);
#else
    auto topOffset = JSThread::GlueData::GetNewSpaceAllocationTopAddressOffset(env->Is32Bit());
    auto endOffset = JSThread::GlueData::GetNewSpaceAllocationEndAddressOffset(env->Is32Bit());
    auto topAddress = Load(VariableType::NATIVE_POINTER(), glue_, IntPtr(topOffset));
    auto endAddress = Load(VariableType::NATIVE_POINTER(), glue_, IntPtr(endOffset));
    auto top = Load(VariableType::JS_POINTER(), topAddress, IntPtr(0));
    auto end = Load(VariableType::JS_POINTER(), endAddress, IntPtr(0));
    DEFVARIABLE(ret, VariableType::JS_ANY(), Undefined());
    auto newTop = PtrAdd(top, size_);
    Branch(IntPtrGreaterThan(newTop, end), &callRuntime, &success);
    Bind(&success);
    {
        Store(VariableType::NATIVE_POINTER(), glue_, topAddress, IntPtr(0), newTop);
        if (env->Is32Bit()) {
            top = ZExtInt32ToInt64(top);
        }
        ret = top;
        result->WriteVariable(*ret);
        Jump(exit);
    }
#endif
    Bind(&callRuntime);
    {
        ret = CallRuntime(glue_, RTSTUB_ID(AllocateInYoung), {
            IntToTaggedTypeNGC(size_) });
        result->WriteVariable(*ret);
        Jump(exit);
    }
}

void NewObjectStubBuilder::InitializeWithSpeicalValue(Label *exit,
    GateRef object, GateRef value, GateRef start, GateRef end)
{
    auto env = GetEnvironment();
    Label begin(env);
    Label storeValue(env);
    Label endLoop(env);

    DEFVARIABLE(startOffset, VariableType::INT32(), start);
    Jump(&begin);
    LoopBegin(&begin);
    {
        Branch(Int32UnsignedLessThan(*startOffset, end), &storeValue, exit);
        Bind(&storeValue);
        {
            Store(VariableType::INT64(), glue_, object, ChangeInt32ToIntPtr(*startOffset), value);
            startOffset = Int32Add(*startOffset, Int32(JSTaggedValue::TaggedTypeSize()));
            Jump(&endLoop);
        }
        Bind(&endLoop);
        LoopEnd(&begin);
    }
}

void NewObjectStubBuilder::InitializeTaggedArrayWithSpeicalValue(Label *exit,
    GateRef array, GateRef value, GateRef start, GateRef length)
{
    Store(VariableType::INT32(), glue_, array, IntPtr(TaggedArray::LENGTH_OFFSET), length);
    auto offset = Int32Mul(start, Int32(JSTaggedValue::TaggedTypeSize()));
    auto dataOffset = Int32Add(offset, Int32(TaggedArray::DATA_OFFSET));
    offset = Int32Mul(length, Int32(JSTaggedValue::TaggedTypeSize()));
    auto endOffset = Int32Add(offset, Int32(TaggedArray::DATA_OFFSET));
    InitializeWithSpeicalValue(exit, array, value, dataOffset, endOffset);
}

void NewObjectStubBuilder::AllocStringObject(Variable *result, Label *exit, GateRef length, bool compressed)
{
    auto env = GetEnvironment();
    if (compressed) {
        size_ = AlignUp(ComputeSizeUtf8(ChangeInt32ToIntPtr(length)),
            IntPtr(static_cast<size_t>(MemAlignment::MEM_ALIGN_OBJECT)));
    } else {
        size_ = AlignUp(ComputeSizeUtf16(ChangeInt32ToIntPtr(length)),
            IntPtr(static_cast<size_t>(MemAlignment::MEM_ALIGN_OBJECT)));
    }
    Label afterAllocate(env);
    AllocateInYoung(result, &afterAllocate);
    
    Bind(&afterAllocate);
    GateRef arrayClass = GetGlobalConstantValue(VariableType::JS_POINTER(), glue_,
                                                ConstantIndex::STRING_CLASS_INDEX);
    StoreHClass(glue_, result->ReadVariable(), arrayClass);
    SetLength(glue_, result->ReadVariable(), length, compressed);
    SetRawHashcode(glue_, result->ReadVariable(), Int32(0));
    Jump(exit);
}
}  // namespace panda::ecmascript::kungfu