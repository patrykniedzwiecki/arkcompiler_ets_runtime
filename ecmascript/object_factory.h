/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
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

#ifndef ECMASCRIPT_OBJECT_FACTORY_H
#define ECMASCRIPT_OBJECT_FACTORY_H

#include "ecmascript/base/error_type.h"
#include "ecmascript/ecma_string.h"
#include "ecmascript/js_function_kind.h"
#include "ecmascript/js_handle.h"
#include "ecmascript/js_hclass.h"
#include "ecmascript/js_native_pointer.h"
#include "ecmascript/js_tagged_value.h"
#include "ecmascript/mem/heap_region_allocator.h"
#include "ecmascript/mem/machine_code.h"
#include "ecmascript/mem/native_area_allocator.h"
#include "ecmascript/mem/space.h"
#include "ecmascript/tagged_array.h"

namespace panda::ecmascript {
struct MethodLiteral;
class Method;
class JSObject;
class JSArray;
class JSAPIPlainArray;
class JSSymbol;
class JSFunctionBase;
class JSFunction;
class JSBoundFunction;
class JSProxyRevocFunction;
class JSAsyncAwaitStatusFunction;
class JSPrimitiveRef;
class GlobalEnv;
class GlobalEnvConstants;
class AccessorData;
class JSGlobalObject;
class LexicalEnv;
class JSDate;
class JSProxy;
class JSRealm;
class JSArguments;
class TaggedQueue;
class JSForInIterator;
class JSSet;
class JSMap;
class JSRegExp;
class JSSetIterator;
class JSRegExpIterator;
class JSMapIterator;
class JSArrayIterator;
class JSAPIPlainArrayIterator;
class JSStringIterator;
class JSGeneratorObject;
class CompletionRecord;
class GeneratorContext;
class JSArrayBuffer;
class JSDataView;
class JSPromise;
class JSPromiseReactionsFunction;
class JSPromiseExecutorFunction;
class JSPromiseAllResolveElementFunction;
class JSAsyncGeneratorResNextRetProRstFtn;
class JSPromiseAnyRejectElementFunction;
class JSPromiseAllSettledElementFunction;
class JSPromiseFinallyFunction;
class JSPromiseValueThunkOrThrowerFunction;
class PromiseReaction;
class PromiseCapability;
class PromiseIteratorRecord;
class JSAsyncFuncObject;
class JSAsyncFunction;
class PromiseRecord;
class JSLocale;
class ResolvingFunctionsRecord;
class EcmaVM;
class Heap;
class ConstantPool;
class Program;
class LayoutInfo;
class JSIntlBoundFunction;
class FreeObject;
class JSNativePointer;
class TSObjectType;
class TSClassType;
class TSUnionType;
class TSInterfaceType;
class TSTypeTable;
class TSClassInstanceType;
class TSFunctionType;
class TSArrayType;
class TSImportType;
class TSObjLayoutInfo;
class TSModuleTable;
class TSFunctionType;
class TSArrayType;
class JSAPIArrayList;
class JSAPIArrayListIterator;
class JSAPIDeque;
class JSAPIDequeIterator;
class TaggedHashArray;
class LinkedNode;
class RBTreeNode;
class JSAPIHashMap;
class JSAPIHashSet;
class JSAPIHashMapIterator;
class JSAPIHashSetIterator;
class JSAPILightWeightMap;
class JSAPILightWeightMapIterator;
class JSAPILightWeightSet;
class JSAPILightWeightSetIterator;
class JSAPIQueue;
class JSAPIQueueIterator;
class JSAPIStack;
class JSAPIStackIterator;
class JSAPITreeSet;
class JSAPITreeMap;
class JSAPITreeSetIterator;
class JSAPITreeMapIterator;
class JSAPIVector;
class JSAPIVectorIterator;
class JSAPILinkedList;
class JSAPIList;
class JSAPILinkedListIterator;
class JSAPIListIterator;
class ModuleNamespace;
class ImportEntry;
class LocalExportEntry;
class IndirectExportEntry;
class StarExportEntry;
class SourceTextModule;
class CjsModule;
class CjsRequire;
class CjsExports;
class ResolvedBinding;
class BigInt;
class AsyncGeneratorRequest;
class JSAsyncGeneratorFunction;
class JSAsyncGeneratorObject;
class CellRecord;
namespace job {
class MicroJobQueue;
class PendingJob;
}  // namespace job
class TransitionHandler;
class PrototypeHandler;
class PropertyBox;
class ProtoChangeMarker;
class ProtoChangeDetails;
class ProfileTypeInfo;
class MachineCode;
class ClassInfoExtractor;

enum class CompletionRecordType : uint8_t;
enum class PrimitiveType : uint8_t;
enum class IterationKind : uint8_t;
enum class MethodIndex : uint8_t;

using ErrorType = base::ErrorType;
using base::ErrorType;
using DeleteEntryPoint = void (*)(void *, void *);

enum class RemoveSlots { YES, NO };

constexpr uint8_t INVALID_BUILTINS_ID = 0xFF;

class ObjectFactory {
public:
    ObjectFactory(JSThread *thread, Heap *heap);
    ~ObjectFactory() = default;
    JSHandle<Method> NewMethodForNativeFunction(const void *func, uint8_t builtinId = INVALID_BUILTINS_ID);

    JSHandle<ProfileTypeInfo> NewProfileTypeInfo(uint32_t length);
    JSHandle<ConstantPool> NewConstantPool(uint32_t capacity);
    JSHandle<Program> NewProgram();

    JSHandle<JSObject> GetJSError(const ErrorType &errorType, const char *data = nullptr, bool needCheckStack = true);

    JSHandle<JSObject> NewJSError(const ErrorType &errorType, const JSHandle<EcmaString> &message,
        bool needCheckStack = true);

    JSHandle<JSObject> NewJSAggregateError();

    JSHandle<TransitionHandler> NewTransitionHandler();

    JSHandle<PrototypeHandler> NewPrototypeHandler();

    JSHandle<JSObject> NewEmptyJSObject();

    // use for others create, prototype is Function.prototype
    // use for native function
    JSHandle<JSFunction> NewJSFunction(const JSHandle<GlobalEnv> &env, const void *nativeFunc = nullptr,
                                       FunctionKind kind = FunctionKind::NORMAL_FUNCTION,
                                       uint8_t builtinId = INVALID_BUILTINS_ID);
    // use for method
    JSHandle<JSFunction> NewJSFunction(const JSHandle<GlobalEnv> &env, const JSHandle<Method> &method,
                                       FunctionKind kind = FunctionKind::NORMAL_FUNCTION);

    JSHandle<JSFunction> NewJSNativeErrorFunction(const JSHandle<GlobalEnv> &env, const void *nativeFunc = nullptr);

    JSHandle<JSFunction> NewSpecificTypedArrayFunction(const JSHandle<GlobalEnv> &env,
                                                       const void *nativeFunc = nullptr);

    JSHandle<JSObject> OrdinaryNewJSObjectCreate(const JSHandle<JSTaggedValue> &proto);

    JSHandle<JSObject> CreateNullJSObject();

    JSHandle<JSFunction> NewAotFunction(uint32_t numArgs, uintptr_t codeEntry);

    JSHandle<JSBoundFunction> NewJSBoundFunction(const JSHandle<JSFunctionBase> &target,
                                                 const JSHandle<JSTaggedValue> &boundThis,
                                                 const JSHandle<TaggedArray> &args);

    JSHandle<JSIntlBoundFunction> NewJSIntlBoundFunction(MethodIndex idx, int functionLength = 1);

    JSHandle<JSProxyRevocFunction> NewJSProxyRevocFunction(const JSHandle<JSProxy> &proxy);

    JSHandle<JSAsyncAwaitStatusFunction> NewJSAsyncAwaitStatusFunction(MethodIndex idx);
    JSHandle<JSFunction> NewJSGeneratorFunction(const JSHandle<Method> &method);

    JSHandle<JSAsyncFunction> NewAsyncFunction(const JSHandle<Method> &method);

    JSHandle<JSGeneratorObject> NewJSGeneratorObject(JSHandle<JSTaggedValue> generatorFunction);

    JSHandle<JSAsyncFuncObject> NewJSAsyncFuncObject();
    JSHandle<JSAsyncGeneratorObject> NewJSAsyncGeneratorObject(JSHandle<JSTaggedValue> generatorFunction);

    JSHandle<JSPrimitiveRef> NewJSPrimitiveRef(const JSHandle<JSFunction> &function,
                                               const JSHandle<JSTaggedValue> &object);
    JSHandle<JSPrimitiveRef> NewJSPrimitiveRef(PrimitiveType type, const JSHandle<JSTaggedValue> &object);

    // get JSHClass for Ecma ClassLinker
    JSHandle<GlobalEnv> NewGlobalEnv(JSHClass *globalEnvClass);

    // get JSHClass for Ecma ClassLinker
    JSHandle<LexicalEnv> NewLexicalEnv(int numSlots);

    inline LexicalEnv *InlineNewLexicalEnv(int numSlots);

    JSHandle<JSSymbol> NewJSSymbol();

    JSHandle<JSSymbol> NewPrivateSymbol();

    JSHandle<JSSymbol> NewPrivateNameSymbol(const JSHandle<JSTaggedValue> &name);

    JSHandle<JSSymbol> NewWellKnownSymbol(const JSHandle<JSTaggedValue> &name);

    JSHandle<JSSymbol> NewPublicSymbol(const JSHandle<JSTaggedValue> &name);

    JSHandle<JSSymbol> NewSymbolWithTable(const JSHandle<JSTaggedValue> &name);

    JSHandle<JSSymbol> NewPrivateNameSymbolWithChar(const char *description);

    JSHandle<JSSymbol> NewWellKnownSymbolWithChar(const char *description);

    JSHandle<JSSymbol> NewPublicSymbolWithChar(const char *description);

    JSHandle<JSSymbol> NewSymbolWithTableWithChar(const char *description);

    JSHandle<AccessorData> NewAccessorData();
    JSHandle<AccessorData> NewInternalAccessor(void *setter, void *getter);

    JSHandle<PromiseCapability> NewPromiseCapability();

    JSHandle<PromiseReaction> NewPromiseReaction();

    JSHandle<PromiseRecord> NewPromiseRecord();
    JSHandle<AsyncGeneratorRequest> NewAsyncGeneratorRequest();

    JSHandle<ResolvingFunctionsRecord> NewResolvingFunctionsRecord();

    JSHandle<PromiseIteratorRecord> NewPromiseIteratorRecord(const JSHandle<JSTaggedValue> &itor, bool done);

    JSHandle<job::MicroJobQueue> NewMicroJobQueue();

    JSHandle<job::PendingJob> NewPendingJob(const JSHandle<JSFunction> &func, const JSHandle<TaggedArray> &argv);

    JSHandle<JSArray> NewJSArray();

    JSHandle<JSProxy> NewJSProxy(const JSHandle<JSTaggedValue> &target, const JSHandle<JSTaggedValue> &handler);
    JSHandle<JSRealm> NewJSRealm();

    JSHandle<JSArguments> NewJSArguments();

    JSHandle<JSPrimitiveRef> NewJSString(const JSHandle<JSTaggedValue> &str);

    JSHandle<TaggedArray> NewTaggedArray(uint32_t length, JSTaggedValue initVal = JSTaggedValue::Hole());
    JSHandle<TaggedArray> NewTaggedArray(uint32_t length, JSTaggedValue initVal, bool nonMovable);
    JSHandle<TaggedArray> NewTaggedArray(uint32_t length, JSTaggedValue initVal, MemSpaceType spaceType);
    JSHandle<TaggedArray> NewDictionaryArray(uint32_t length);
    JSHandle<JSForInIterator> NewJSForinIterator(const JSHandle<JSTaggedValue> &obj);

    JSHandle<PropertyBox> NewPropertyBox(const JSHandle<JSTaggedValue> &name);

    JSHandle<ProtoChangeMarker> NewProtoChangeMarker();

    JSHandle<ProtoChangeDetails> NewProtoChangeDetails();
    JSHandle<BigInt> NewBigInt(uint32_t length);
    // use for copy properties keys's array to another array
    JSHandle<TaggedArray> ExtendArray(const JSHandle<TaggedArray> &old, uint32_t length,
                                      JSTaggedValue initVal = JSTaggedValue::Hole(),
                                      MemSpaceType type = MemSpaceType::SEMI_SPACE);
    JSHandle<TaggedArray> CopyPartArray(const JSHandle<TaggedArray> &old, uint32_t start, uint32_t end);
    JSHandle<TaggedArray> CopyArray(const JSHandle<TaggedArray> &old, uint32_t oldLength, uint32_t newLength,
                                    JSTaggedValue initVal = JSTaggedValue::Hole(),
                                    MemSpaceType type = MemSpaceType::SEMI_SPACE);
    JSHandle<TaggedArray> CloneProperties(const JSHandle<TaggedArray> &old);
    JSHandle<TaggedArray> CloneProperties(const JSHandle<TaggedArray> &old, const JSHandle<JSTaggedValue> &env,
                                          const JSHandle<JSObject> &obj);

    JSHandle<LayoutInfo> CreateLayoutInfo(int properties, MemSpaceType type = MemSpaceType::SEMI_SPACE,
                                          JSTaggedValue initVal = JSTaggedValue::Hole());

    JSHandle<LayoutInfo> ExtendLayoutInfo(const JSHandle<LayoutInfo> &old, int properties,
                                          JSTaggedValue initVal = JSTaggedValue::Hole());

    JSHandle<LayoutInfo> CopyLayoutInfo(const JSHandle<LayoutInfo> &old);

    JSHandle<LayoutInfo> CopyAndReSort(const JSHandle<LayoutInfo> &old, int end, int capacity);

    JSHandle<EcmaString> GetEmptyString() const;

    JSHandle<TaggedArray> EmptyArray() const;

    FreeObject *FillFreeObject(uintptr_t address, size_t size, RemoveSlots removeSlots = RemoveSlots::NO);

    TaggedObject *NewObject(const JSHandle<JSHClass> &hclass);

    TaggedObject *NewNonMovableObject(const JSHandle<JSHClass> &hclass, int inobjPropCount = 0);

    void InitializeExtraProperties(const JSHandle<JSHClass> &hclass, TaggedObject *obj, int inobjPropCount);

    JSHandle<TaggedQueue> NewTaggedQueue(uint32_t length);

    JSHandle<TaggedQueue> GetEmptyTaggedQueue() const;

    JSHandle<JSSetIterator> NewJSSetIterator(const JSHandle<JSSet> &set, IterationKind kind);

    JSHandle<JSRegExpIterator> NewJSRegExpIterator(const JSHandle<JSTaggedValue> &matcher,
                                                   const JSHandle<EcmaString> &inputStr, bool global,
                                                   bool fullUnicode);

    JSHandle<JSMapIterator> NewJSMapIterator(const JSHandle<JSMap> &map, IterationKind kind);

    JSHandle<JSArrayIterator> NewJSArrayIterator(const JSHandle<JSObject> &array, IterationKind kind);

    JSHandle<CompletionRecord> NewCompletionRecord(CompletionRecordType type, JSHandle<JSTaggedValue> value);

    JSHandle<GeneratorContext> NewGeneratorContext();

    JSHandle<JSPromiseReactionsFunction> CreateJSPromiseReactionsFunction(MethodIndex idx);

    JSHandle<JSPromiseExecutorFunction> CreateJSPromiseExecutorFunction();

    JSHandle<JSPromiseAllResolveElementFunction> NewJSPromiseAllResolveElementFunction();

    JSHandle<JSPromiseAnyRejectElementFunction> NewJSPromiseAnyRejectElementFunction();

    JSHandle<JSPromiseAllSettledElementFunction> NewJSPromiseAllSettledResolveElementFunction();

    JSHandle<JSPromiseAllSettledElementFunction> NewJSPromiseAllSettledRejectElementFunction();

    JSHandle<JSPromiseFinallyFunction> NewJSPromiseThenFinallyFunction();

    JSHandle<JSPromiseFinallyFunction> NewJSPromiseCatchFinallyFunction();

    JSHandle<JSPromiseValueThunkOrThrowerFunction> NewJSPromiseValueThunkFunction();

    JSHandle<JSPromiseValueThunkOrThrowerFunction> NewJSPromiseThrowerFunction();

    JSHandle<JSAsyncGeneratorResNextRetProRstFtn> NewJSAsyGenResNextRetProRstFulfilledFtn();

    JSHandle<JSAsyncGeneratorResNextRetProRstFtn> NewJSAsyGenResNextRetProRstRejectedFtn();

    JSHandle<JSObject> CloneObjectLiteral(JSHandle<JSObject> object, const JSHandle<JSTaggedValue> &env,
                                          bool canShareHClass = true);
    JSHandle<JSObject> CloneObjectLiteral(JSHandle<JSObject> object);
    JSHandle<JSArray> CloneArrayLiteral(JSHandle<JSArray> object);
    JSHandle<JSFunction> CloneJSFuction(JSHandle<JSFunction> obj, FunctionKind kind);
    JSHandle<JSFunction> CloneClassCtor(JSHandle<JSFunction> ctor, const JSHandle<JSTaggedValue> &lexenv,
                                        bool canShareHClass);

    void NewJSArrayBufferData(const JSHandle<JSArrayBuffer> &array, int32_t length);

    JSHandle<JSArrayBuffer> NewJSArrayBuffer(int32_t length);

    JSHandle<JSArrayBuffer> NewJSArrayBuffer(void *buffer, int32_t length, const DeleteEntryPoint &deleter, void *data,
                                             bool share = false);

    JSHandle<JSDataView> NewJSDataView(JSHandle<JSArrayBuffer> buffer, uint32_t offset, uint32_t length);

    void NewJSSharedArrayBufferData(const JSHandle<JSArrayBuffer> &array, int32_t length);

    JSHandle<JSArrayBuffer> NewJSSharedArrayBuffer(int32_t length);

    JSHandle<JSArrayBuffer> NewJSSharedArrayBuffer(void *buffer, int32_t length);

    void NewJSRegExpByteCodeData(const JSHandle<JSRegExp> &regexp, void *buffer, size_t size);

    template<typename T, typename S>
    inline void NewJSIntlIcuData(const JSHandle<T> &obj, const S &icu, const DeleteEntryPoint &callback);

    EcmaString *InternString(const JSHandle<JSTaggedValue> &key);

    inline JSHandle<JSNativePointer> NewJSNativePointer(void *externalPointer,
                                                        const DeleteEntryPoint &callBack = nullptr,
                                                        void *data = nullptr,
                                                        bool nonMovable = false);

    JSHandle<JSObject> NewOldSpaceObjLiteralByHClass(const JSHandle<TaggedArray> &properties, size_t length);
    JSHandle<JSHClass> SetLayoutInObjHClass(const JSHandle<TaggedArray> &properties, size_t length,
                                            const JSHandle<JSHClass> &objClass);
    JSHandle<JSHClass> GetObjectLiteralHClass(const JSHandle<TaggedArray> &properties, size_t length);
    // only use for creating Function.prototype and Function
    JSHandle<JSFunction> NewJSFunctionByHClass(const JSHandle<Method> &method, const JSHandle<JSHClass> &clazz,
                                                 FunctionKind kind = FunctionKind::NORMAL_FUNCTION,
                                                 MemSpaceType type = MemSpaceType::SEMI_SPACE);
    JSHandle<JSFunction> NewJSFunctionByHClass(const void *func, const JSHandle<JSHClass> &clazz,
                                                 FunctionKind kind = FunctionKind::NORMAL_FUNCTION);
    JSHandle<Method> NewMethod(const MethodLiteral *methodLiteral);

    // used for creating jsobject by constructor
    JSHandle<JSObject> NewJSObjectByConstructor(const JSHandle<JSFunction> &constructor,
                                                const JSHandle<JSTaggedValue> &newTarget);
    JSHandle<JSObject> NewJSObjectByConstructor(const JSHandle<JSFunction> &constructor);
    void InitializeJSObject(const JSHandle<JSObject> &obj, const JSHandle<JSHClass> &jshclass);

    JSHandle<JSObject> NewJSObjectWithInit(const JSHandle<JSHClass> &jshclass);
    uintptr_t NewSpaceBySnapshotAllocator(size_t size);
    JSHandle<MachineCode> NewMachineCodeObject(size_t length, const uint8_t *data);
    JSHandle<ClassInfoExtractor> NewClassInfoExtractor(JSHandle<JSTaggedValue> method);

    // ----------------------------------- new TSType ----------------------------------------
    JSHandle<TSObjLayoutInfo> CreateTSObjLayoutInfo(int propNum, JSTaggedValue initVal = JSTaggedValue::Hole());
    JSHandle<TSObjectType> NewTSObjectType(uint32_t numOfKeys);
    JSHandle<TSClassType> NewTSClassType();
    JSHandle<TSUnionType> NewTSUnionType(uint32_t length);
    JSHandle<TSInterfaceType> NewTSInterfaceType();
    JSHandle<TSImportType> NewTSImportType();
    JSHandle<TSClassInstanceType> NewTSClassInstanceType();
    JSHandle<TSTypeTable> NewTSTypeTable(uint32_t length);
    JSHandle<TSModuleTable> NewTSModuleTable(uint32_t length);
    JSHandle<TSFunctionType> NewTSFunctionType(uint32_t length);
    JSHandle<TSArrayType> NewTSArrayType();

    // ----------------------------------- new string ----------------------------------------
    JSHandle<EcmaString> NewFromASCII(const CString &data);
    JSHandle<EcmaString> NewFromUtf8(const CString &data);

    JSHandle<EcmaString> NewFromStdString(const std::string &data);

    JSHandle<EcmaString> NewFromUtf8(const uint8_t *utf8Data, uint32_t utf8Len);

    JSHandle<EcmaString> NewFromUtf16(const uint16_t *utf16Data, uint32_t utf16Len);
    JSHandle<EcmaString> NewFromUtf16Compress(const uint16_t *utf16Data, uint32_t utf16Len);
    JSHandle<EcmaString> NewFromUtf16NotCompress(const uint16_t *utf16Data, uint32_t utf16Len);

    JSHandle<EcmaString> NewFromUtf8Literal(const uint8_t *utf8Data, uint32_t utf8Len);
    JSHandle<EcmaString> NewFromUtf8LiteralCompress(const uint8_t *utf8Data, uint32_t utf8Len);

    JSHandle<EcmaString> NewFromUtf16Literal(const uint16_t *utf16Data, uint32_t utf16Len);
    JSHandle<EcmaString> NewFromUtf16LiteralCompress(const uint16_t *utf16Data, uint32_t utf16Len);
    JSHandle<EcmaString> NewFromUtf16LiteralNotCompress(const uint16_t *utf16Data, uint32_t utf16Len);

    JSHandle<EcmaString> ConcatFromString(const JSHandle<EcmaString> &firstString,
                                          const JSHandle<EcmaString> &secondString);

    // used for creating Function
    JSHandle<JSObject> NewJSObject(const JSHandle<JSHClass> &jshclass);

    // used for creating jshclass in Builtins, Function, Class_Linker
    JSHandle<JSHClass> NewEcmaHClass(uint32_t size, JSType type, const JSHandle<JSTaggedValue> &prototype);

    // It is used to provide iterators for non ECMA standard jsapi containers.
    JSHandle<JSAPIPlainArray> NewJSAPIPlainArray(uint32_t capacity);
    JSHandle<JSAPIPlainArrayIterator> NewJSAPIPlainArrayIterator(const JSHandle<JSAPIPlainArray> &plainarray,
                                                                 IterationKind kind);
    JSHandle<JSAPIArrayList> NewJSAPIArrayList(uint32_t capacity);

    JSHandle<JSAPILightWeightMapIterator> NewJSAPILightWeightMapIterator(const JSHandle<JSAPILightWeightMap> &obj,
                                                                         IterationKind kind);
    JSHandle<JSAPILightWeightSetIterator> NewJSAPILightWeightSetIterator(const JSHandle<JSAPILightWeightSet> &obj,
                                                                         IterationKind kind);
    JSHandle<TaggedArray> CopyQueue(const JSHandle<TaggedArray> &old, uint32_t newLength,
                                    uint32_t front, uint32_t tail);
    JSHandle<JSAPIQueueIterator> NewJSAPIQueueIterator(const JSHandle<JSAPIQueue> &queue);
    JSHandle<TaggedArray> CopyDeque(const JSHandle<TaggedArray> &old, uint32_t newLength, uint32_t oldLength,
                                    uint32_t first, uint32_t last);
    JSHandle<JSAPIDequeIterator> NewJSAPIDequeIterator(const JSHandle<JSAPIDeque> &deque);
    JSHandle<JSAPIArrayListIterator> NewJSAPIArrayListIterator(const JSHandle<JSAPIArrayList> &arrayList);
    JSHandle<JSAPIList> NewJSAPIList();
    JSHandle<JSAPILinkedList> NewJSAPILinkedList();
    JSHandle<JSAPILinkedListIterator> NewJSAPILinkedListIterator(const JSHandle<JSAPILinkedList> &linkedList);
    JSHandle<JSAPIListIterator> NewJSAPIListIterator(const JSHandle<JSAPIList> &list);
    JSHandle<JSAPITreeMapIterator> NewJSAPITreeMapIterator(const JSHandle<JSAPITreeMap> &map, IterationKind kind);
    JSHandle<JSAPITreeSetIterator> NewJSAPITreeSetIterator(const JSHandle<JSAPITreeSet> &set, IterationKind kind);
    JSHandle<JSAPIStackIterator> NewJSAPIStackIterator(const JSHandle<JSAPIStack> &stack);
    JSHandle<JSAPIVector> NewJSAPIVector(uint32_t capacity);
    JSHandle<JSAPIVectorIterator> NewJSAPIVectorIterator(const JSHandle<JSAPIVector> &vector);
    JSHandle<JSAPIHashMapIterator> NewJSAPIHashMapIterator(const JSHandle<JSAPIHashMap> &hashMap, IterationKind kind);
    JSHandle<JSAPIHashSetIterator> NewJSAPIHashSetIterator(const JSHandle<JSAPIHashSet> &hashSet, IterationKind kind);
    JSHandle<TaggedHashArray> NewTaggedHashArray(uint32_t length);
    JSHandle<LinkedNode> NewLinkedNode(int hash, const JSHandle<JSTaggedValue> &key,
                                       const JSHandle<JSTaggedValue> &value,
                                       const JSHandle<LinkedNode> &next);
    JSHandle<RBTreeNode> NewTreeNode(int hash, const JSHandle<JSTaggedValue> &key,
                                     const JSHandle<JSTaggedValue> &value);
    // --------------------------------------module--------------------------------------------
    JSHandle<ModuleNamespace> NewModuleNamespace();
    JSHandle<ImportEntry> NewImportEntry();
    JSHandle<ImportEntry> NewImportEntry(const JSHandle<JSTaggedValue> &moduleRequest,
                                         const JSHandle<JSTaggedValue> &importName,
                                         const JSHandle<JSTaggedValue> &localName);
    JSHandle<LocalExportEntry> NewLocalExportEntry();
    JSHandle<LocalExportEntry> NewLocalExportEntry(const JSHandle<JSTaggedValue> &exportName,
                                                   const JSHandle<JSTaggedValue> &localName);
    JSHandle<IndirectExportEntry> NewIndirectExportEntry();
    JSHandle<IndirectExportEntry> NewIndirectExportEntry(const JSHandle<JSTaggedValue> &exportName,
                                                         const JSHandle<JSTaggedValue> &moduleRequest,
                                                         const JSHandle<JSTaggedValue> &importName);
    JSHandle<StarExportEntry> NewStarExportEntry();
    JSHandle<StarExportEntry> NewStarExportEntry(const JSHandle<JSTaggedValue> &moduleRequest);
    JSHandle<SourceTextModule> NewSourceTextModule();
    JSHandle<ResolvedBinding> NewResolvedBindingRecord();
    JSHandle<ResolvedBinding> NewResolvedBindingRecord(const JSHandle<SourceTextModule> &module,
                                                       const JSHandle<JSTaggedValue> &bindingName);
    JSHandle<CellRecord> NewCellRecord();
    JSHandle<JSFunction> NewJSAsyncGeneratorFunction(const JSHandle<Method> &method);
    // --------------------------------------require--------------------------------------------
    JSHandle<CjsModule> NewCjsModule();
    JSHandle<CjsExports> NewCjsExports();
    JSHandle<CjsRequire> NewCjsRequire();

    JSHandle<JSHClass> CreateIteratorResultInstanceClass();

    // --------------------------------------old space object--------------------------------------------
    JSHandle<JSObject> NewOldSpaceJSObject(const JSHandle<JSHClass> &jshclass);
    TaggedObject *NewOldSpaceObject(const JSHandle<JSHClass> &hclass);
    JSHandle<TaggedArray> NewOldSpaceTaggedArray(uint32_t length, JSTaggedValue initVal = JSTaggedValue::Hole());

    // ---------------------------------New objects used internally--------------------------------------
    JSHandle<JSArray> NewJSStableArrayWithElements(const JSHandle<TaggedArray> &elements);

private:
    friend class GlobalEnv;
    friend class GlobalEnvConstants;
    friend class EcmaString;
    friend class SnapshotProcessor;
    void InitObjectFields(const TaggedObject *object);

    JSThread *thread_ {nullptr};
    bool isTriggerGc_ {false};
    bool triggerSemiGC_ {false};

    EcmaVM *vm_ {nullptr};
    Heap *heap_ {nullptr};

    NO_COPY_SEMANTIC(ObjectFactory);
    NO_MOVE_SEMANTIC(ObjectFactory);

    void NewObjectHook() const;

    // used for creating jshclass in Builtins, Function, Class_Linker
    JSHandle<JSHClass> NewEcmaHClass(uint32_t size, JSType type,
                                       uint32_t inlinedProps = JSHClass::DEFAULT_CAPACITY_OF_IN_OBJECTS);
    // used for creating jshclass in GlobalEnv, EcmaVM
    JSHandle<JSHClass> NewEcmaHClassClass(JSHClass *hclass, uint32_t size, JSType type);
    JSHandle<JSHClass> NewEcmaHClass(JSHClass *hclass, uint32_t size, JSType type,
                                       uint32_t inlinedProps = JSHClass::DEFAULT_CAPACITY_OF_IN_OBJECTS);
    JSHandle<JSHClass> NewEcmaReadOnlyHClass(JSHClass *hclass, uint32_t size, JSType type,
                                               uint32_t inlinedProps = JSHClass::DEFAULT_CAPACITY_OF_IN_OBJECTS);
    JSHandle<JSHClass> InitClassClass();

    // used to create nonmovable js_object
    JSHandle<JSObject> NewNonMovableJSObject(const JSHandle<JSHClass> &jshclass);

    // used to create nonmovable utf8 string at global constants
    JSHandle<EcmaString> NewFromASCIINonMovable(const CString &data);

    // used for creating Function
    JSHandle<JSFunction> NewJSFunction(const JSHandle<GlobalEnv> &env, const JSHandle<JSHClass> &hclass);
    JSHandle<JSHClass> CreateObjectClass(const JSHandle<TaggedArray> &keys, const JSHandle<TaggedArray> &values);
    JSHandle<JSHClass> CreateObjectClass(const JSHandle<TaggedArray> &properties, size_t length);
    JSHandle<JSHClass> CreateFunctionClass(FunctionKind kind, uint32_t size, JSType type,
                                           const JSHandle<JSTaggedValue> &prototype);

    // used for creating ref.prototype in buildins, such as Number.prototype
    JSHandle<JSPrimitiveRef> NewJSPrimitiveRef(const JSHandle<JSHClass> &hclass,
                                               const JSHandle<JSTaggedValue> &object);

    JSHandle<EcmaString> GetStringFromStringTable(const uint8_t *utf8Data, uint32_t utf8Len, bool canBeCompress) const;
    JSHandle<EcmaString> GetStringFromStringTableNonMovable(const uint8_t *utf8Data, uint32_t utf8Len) const;
    // For MUtf-8 string data
    EcmaString *GetRawStringFromStringTable(const uint8_t *mutf8Data, uint32_t utf16Len, bool canBeCompressed,
                                            MemSpaceType type = MemSpaceType::SEMI_SPACE) const;

    JSHandle<EcmaString> GetStringFromStringTable(const uint16_t *utf16Data, uint32_t utf16Len,
                                                  bool canBeCompress) const;

    JSHandle<EcmaString> GetStringFromStringTable(EcmaString *string) const;

    JSHandle<EcmaString> GetStringFromStringTable(const JSHandle<EcmaString> &firstString,
                                                  const JSHandle<EcmaString> &secondString);

    inline EcmaString *AllocStringObject(size_t size);
    inline EcmaString *AllocOldSpaceStringObject(size_t size);
    inline EcmaString *AllocNonMovableStringObject(size_t size);
    JSHandle<TaggedArray> NewEmptyArray();  // only used for EcmaVM.

    JSHandle<JSHClass> CreateJSArguments();
    JSHandle<JSHClass> CreateJSArrayInstanceClass(JSHandle<JSTaggedValue> proto);
    JSHandle<JSHClass> CreateJSRegExpInstanceClass(JSHandle<JSTaggedValue> proto);

    inline TaggedObject *AllocObjectWithSpaceType(size_t size, JSHClass *cls, MemSpaceType type);

    friend class Builtins;    // create builtins object need hclass
    friend class JSFunction;  // create prototype_or_hclass need hclass
    friend class JSHClass;    // HC transition need hclass
    friend class EcmaVM;      // hold the factory instance
    friend class JsVerificationTest;
    friend class PandaFileTranslator;
    friend class LiteralDataExtractor;
    friend class RuntimeStubs;
    friend class ClassInfoExtractor;
    friend class TSObjectType;
    friend class ModuleDataExtractor;
    friend class ModuleDataAccessor;
    friend class ConstantPool;
};

class ClassLinkerFactory {
private:
    friend class GlobalEnv;  // root class in class_linker need hclass
    friend class EcmaVM;     // root class in class_linker need hclass
};
}  // namespace panda::ecmascript
#endif  // ECMASCRIPT_OBJECT_FACTORY_H
