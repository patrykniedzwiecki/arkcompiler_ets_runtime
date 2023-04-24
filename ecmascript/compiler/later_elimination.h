/*
 * Copyright (c) 2023 Huawei Device Co., Ltd.
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

#ifndef ECMASCRIPT_COMPILER_LATER_ELIMINATION_H
#define ECMASCRIPT_COMPILER_LATER_ELIMINATION_H

#include "ecmascript/compiler/circuit_builder.h"
#include "ecmascript/compiler/gate_accessor.h"
#include "ecmascript/compiler/graph_visitor.h"
#include "ecmascript/mem/chunk_containers.h"

namespace panda::ecmascript::kungfu {
class LaterElimination;

class DependChainNodes : public ChunkObject {
public:
    DependChainNodes(Chunk* chunk) : chunk_(chunk) {}
    ~DependChainNodes() = default;

    GateRef LookupNode(LaterElimination* elimination, GateRef gate);
    DependChainNodes* UpdateNode(GateRef gate);
    bool Equals(DependChainNodes* that);
    void Merge(DependChainNodes* that);
    void CopyFrom(DependChainNodes *other)
    {
        head_ = other->head_;
        size_ = other->size_;
    }
private:
    struct Node {
        Node(GateRef gate, Node* next) : gate(gate), next(next) {}
        GateRef gate;
        Node *next;
    };

    Node *head_{nullptr};
    size_t size_ {0};
    Chunk* chunk_;
};

class LaterElimination : public GraphVisitor {
public:
    LaterElimination(Circuit *circuit, bool enableLog, const std::string& name, Chunk* chunk)
        : GraphVisitor(circuit, chunk), enableLog_(enableLog),
        methodName_(name), dependChains_(chunk) {}

    ~LaterElimination() = default;

    void Run();

    GateRef VisitGate(GateRef gate) override;
    bool CheckReplacement(GateRef lhs, GateRef rhs);
private:
    bool IsLogEnabled() const
    {
        return enableLog_;
    }

    const std::string& GetMethodName() const
    {
        return methodName_;
    }

    DependChainNodes* GetDependChain(GateRef dependIn)
    {
        size_t idx = acc_.GetId(dependIn);
        ASSERT(idx <= circuit_->GetMaxGateId());
        return dependChains_[idx];
    }

    GateRef VisitDependEntry(GateRef gate);
    GateRef UpdateDependChain(GateRef gate, DependChainNodes* dependInfo);
    GateRef TryEliminateGate(GateRef gate);
    GateRef TryEliminateOther(GateRef gate);
    GateRef TryEliminateDependSelector(GateRef gate);

    bool enableLog_ {false};
    std::string methodName_;
    ChunkVector<DependChainNodes*> dependChains_;
};
}  // panda::ecmascript::kungfu
#endif  // ECMASCRIPT_COMPILER_LATER_ELIMINATION_H