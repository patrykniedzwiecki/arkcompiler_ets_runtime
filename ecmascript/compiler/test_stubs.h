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

#ifndef ECMASCRIPT_COMPILER_TEST_STUBS_H
#define ECMASCRIPT_COMPILER_TEST_STUBS_H

#include "ecmascript/compiler/stub_builder.h"
#include "test_stubs_signature.h"

namespace panda::ecmascript::kungfu {

#ifndef NDEBUG
#define DECLARE_STUB_CLASS(name)                                                   \
    class name##StubBuilder : public StubBuilder {                                 \
    public:                                                                        \
        explicit name##StubBuilder(CallSignature *callSignature, Circuit *circuit) \
            : StubBuilder(callSignature, circuit) {}                               \
        ~name##StubBuilder() = default;                                            \
        NO_MOVE_SEMANTIC(name##StubBuilder);                                       \
        NO_COPY_SEMANTIC(name##StubBuilder);                                       \
        void GenerateCircuit(const CompilationConfig *cfg) override;               \
    };
    TEST_STUB_SIGNATRUE_LIST(DECLARE_STUB_CLASS)
#undef DECLARE_STUB_CLASS
#endif
}
#endif
