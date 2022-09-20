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

#ifndef ECMASCRIPT_COMPILER_TYPE_LOWERING_H
#define ECMASCRIPT_COMPILER_TYPE_LOWERING_H

#include "ecmascript/compiler/argument_accessor.h"
#include "ecmascript/compiler/bytecode_circuit_builder.h"
#include "ecmascript/compiler/circuit_builder-inl.h"

namespace panda::ecmascript::kungfu {
// TypeLowering Process
// SW: state wire, DW: depend wire, VW: value wire
// Before Type Lowering:
//                                    SW   DW   VW
//                                    |    |    |
//                                    |    |    |
//                                    v    v    v
//                                +-------------------+
//                                |       (HIR)       |    SW     +--------------+
//                            --DW|    JS_BYTECODE    |---------->| IF_EXCEPTION |
//                            |   +-------------------+           +--------------+
//                            |            SW       VW
//                            |            |        |
//                            |            v        |
//                            |    +--------------+ |
//                            |    |  IF_SUCCESS  | |
//                            |    +--------------+ |
//                            |            SW       |
//                            |            |        |
//                            |            v        v
//                            |   +-------------------+
//                            |   |       (HIR)       |
//                            --->|    JS_BYTECODE    |
//                                +-------------------+
//
// After Type Lowering:
//                                           SW
//                                           |
//                                           v
//                                 +-------------------+
//                                 |     IF_BRANCH     |
//                                 |    (Type Check)   |
//                                 +-------------------+
//                                    SW            SW
//                                    |             |
//                                    V             V
//                            +--------------+  +--------------+
//                            |    IF_TRUE   |  |   IF_FALSE   |
//                            +--------------+  +--------------+
//                 VW   DW          SW               SW                   DW   VW
//                 |    |           |                |                    |    |
//                 |    |           V                V                    |    |
//                 |    |  +---------------+     +---------------------+  |    |
//                 ------->|   FAST PATH   |     |        (HIR)        |<-------
//                         +---------------+     |     JS_BYTECODE     |
//                            VW  DW   SW        +---------------------+
//                            |   |    |               SW         VW  DW
//                            |   |    |               |          |   |
//                            |   |    |               v          |   |
//                            |   |    |         +--------------+ |   |
//                            |   |    |         |  IF_SUCCESS  | |   |
//                            |   |    |         +--------------+ |   |
//                            |   |    |                SW        |   |
//                            |   |    |                |         |   |
//                            |   |    v                v         |   |
//                            |   |  +---------------------+      |   |
//                            |   |  |        MERGE        |      |   |
//                            |   |  +---------------------+      |   |
//                            |   |    SW         SW    SW        |   |
//                            ----|----|----------|-----|--       |   |
//                             ---|----|----------|-----|-|-------|----
//                             |  |    |          |     | |       |
//                             v  v    v          |     v v       v
//                            +-----------------+ | +----------------+
//                            | DEPEND_SELECTOR | | | VALUE_SELECTOR |
//                            +-----------------+ | +----------------+
//                                    DW          |        VW
//                                    |           |        |
//                                    v           v        v
//                                  +------------------------+
//                                  |         (HIR)          |
//                                  |      JS_BYTECODE       |
//                                  +------------------------+

class TypeLowering {
public:
    TypeLowering(BytecodeCircuitBuilder *bcBuilder, Circuit *circuit, CompilationConfig *cmpCfg, TSManager *tsManager,
                 bool enableLog)
        : bcBuilder_(bcBuilder), circuit_(circuit), acc_(circuit), builder_(circuit, cmpCfg),
          dependEntry_(Circuit::GetCircuitRoot(OpCode(OpCode::DEPEND_ENTRY))), tsManager_(tsManager),
          enableLog_(enableLog) {}
    ~TypeLowering() = default;

    void RunTypeLowering();

private:
    bool IsLogEnabled() const
    {
        return enableLog_;
    }

    void Lower(GateRef gate);
    void LowerType(GateRef gate);
    void LowerTypeCheck(GateRef gate);
    void LowerTypedBinaryOp(GateRef gate);
    void LowerTypeConvert(GateRef gate);
    void LowerTypedUnaryOp(GateRef gate);
    void LowerTypedAdd(GateRef gate);
    void LowerTypedSub(GateRef gate);
    void LowerTypedMul(GateRef gate);
    void LowerTypedLess(GateRef gate);
    void LowerTypedLessEq(GateRef gate);
    void LowerPrimitiveToNumber(GateRef dst, GateRef src, GateType srcType);
    void LowerNumberCheck(GateRef gate);
    void LowerNumberAdd(GateRef gate);
    void LowerNumberSub(GateRef gate);
    void LowerNumberMul(GateRef gate);
    void LowerNumberLess(GateRef gate);
    void LowerNumberLessEq(GateRef gate);
    void GenerateSuccessMerge(std::vector<GateRef> &successControl);
    void RebuildSlowpathCfg(GateRef hir, std::map<GateRef, size_t> &stateGateMap);
    void ReplaceHirToCall(GateRef hirGate, GateRef callGate, bool noThrow = false);
    void ReplaceGateToSubCfg(GateRef gate, GateRef state, GateRef depend, GateRef value);
    void ReplaceHirToFastPathCfg(GateRef hir, GateRef outir, const std::vector<GateRef> &successControl);

    GateRef LowerCallRuntime(GateRef glue, int index, const std::vector<GateRef> &args, bool useLabel = false);
    template<OpCode::Op Op>
    GateRef FastAddOrSubOrMul(GateRef left, GateRef right);
    template<OpCode::Op Op>
    GateRef FastAddOrSubOrMul2Number(GateRef left, GateRef right);
    template<OpCode::Op Op, MachineType Type>
    GateRef BinaryOp(GateRef x, GateRef y);
    GateRef DoubleToTaggedDoublePtr(GateRef gate);
    GateRef ChangeInt32ToFloat64(GateRef gate);
    GateRef GeneralMod(GateRef left, GateRef right, GateRef glue);
    GateRef Int32Mod(GateRef left, GateRef right);
    GateRef DoubleMod(GateRef left, GateRef right);
    GateRef IntToTaggedNGc(GateRef x);
    GateRef DoubleIsINF(GateRef x);
    GateRef Less(GateRef left, GateRef right);
    GateRef LessEq(GateRef left, GateRef right);
    GateRef Less2Number(GateRef left, GateRef right);
    GateRef LessEq2Number(GateRef left, GateRef right);
    GateRef FastEqual(GateRef left, GateRef right);
    GateRef FastDiv(GateRef left, GateRef right);

    void LowerTypeAdd2(GateRef gate, GateRef glue);
    void LowerTypeSub2(GateRef gate);
    void LowerTypeMul2(GateRef gate);
    void LowerTypeMod2(GateRef gate, GateRef glue);
    void LowerTypeLess2(GateRef gate);
    void LowerTypeLessEq2(GateRef gate);
    void LowerTypeGreater(GateRef gate);
    void LowerTypeGreaterEq(GateRef gate);
    void LowerTypeDiv2(GateRef gate);
    void LowerTypeEq(GateRef gate);
    void LowerTypeNotEq(GateRef gate);
    void LowerToNumeric(GateRef gate);
    void LowerTypeInc(GateRef gate);

    GateType GetLeftType(GateRef gate);
    GateType GetRightType(GateRef gate);

    BytecodeCircuitBuilder *bcBuilder_;
    Circuit *circuit_;
    GateAccessor acc_;
    CircuitBuilder builder_;
    GateRef dependEntry_;
    [[maybe_unused]] TSManager *tsManager_ {nullptr};
    bool enableLog_ {false};
};
}  // panda::ecmascript::kungfu
#endif  // ECMASCRIPT_COMPILER_TYPE_LOWERING_H
