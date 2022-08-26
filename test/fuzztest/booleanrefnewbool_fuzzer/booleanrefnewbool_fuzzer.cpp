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

#include "booleanrefnewbool_fuzzer.h"
#include "ecmascript/napi/include/jsnapi.h"
#include "ecmascript/tooling/debugger_service.h"
#include "ecmascript/ecma_string-inl.h"

using namespace panda;
using namespace panda::ecmascript;

namespace OHOS {
    void BooleanRefNewBoolFuzzTest(const uint8_t* data, size_t size)
    {
        RuntimeOption option;
        option.SetLogLevel(RuntimeOption::LOG_LEVEL::ERROR);
        auto vm = JSNApi::CreateJSVM(option);
        bool input = true;
        if (size == 0 || data == nullptr) {
            input = false;
        }
        [[maybe_unused]] Local<BooleanRef> ref = BooleanRef::New(vm, input);
        JSNApi::DestroyJSVM(vm);
    }
}

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    // Run your code on data.
    OHOS::BooleanRefNewBoolFuzzTest(data, size);
    return 0;
}