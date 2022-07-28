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

#include "ecmascript/dfx/stackinfo/js_stackinfo.h"

#include "ecmascript/base/builtins_base.h"
#include "ecmascript/ecma_vm.h"
#include "ecmascript/interpreter/frame_handler.h"
#include "ecmascript/interpreter/interpreter.h"
#include "ecmascript/jspandafile/js_pandafile_manager.h"
#include "ecmascript/tooling/backend/js_pt_extractor.h"

namespace panda::ecmascript {
std::string JsStackInfo::BuildJsStackTrace(JSThread *thread, bool needNative)
{
    std::string data;
    FrameHandler frameHandler(thread);
    for (; frameHandler.HasFrame(); frameHandler.PrevInterpretedFrame()) {
        if (!frameHandler.IsInterpretedFrame()) {
            continue;
        }
        auto method = frameHandler.CheckAndGetMethod();
        if (method == nullptr) {
            continue;
        }
        if (!method->IsNativeWithCallField()) {
            data.append("    at ");
            std::string name = method->ParseFunctionName();
            if (name.empty()) {
                name = "anonymous";
            }
            data += name;
            data.append(" (");
            // source file
            tooling::JSPtExtractor *debugExtractor =
                JSPandaFileManager::GetInstance()->GetJSPtExtractor(method->GetJSPandaFile());
            const std::string &sourceFile = debugExtractor->GetSourceFile(method->GetMethodId());
            if (sourceFile.empty()) {
                data.push_back('?');
            } else {
                data += sourceFile;
            }
            data.push_back(':');
            // line number and column number
            auto callbackLineFunc = [&data](int32_t line) -> bool {
                data += std::to_string(line + 1);
                data.push_back(':');
                return true;
            };
            auto callbackColumnFunc = [&data](int32_t column) -> bool {
                data += std::to_string(column + 1);
                return true;
            };
            panda_file::File::EntityId methodId = method->GetMethodId();
            uint32_t offset = frameHandler.GetBytecodeOffset();
            if (!debugExtractor->MatchLineWithOffset(callbackLineFunc, methodId, offset) ||
                !debugExtractor->MatchColumnWithOffset(callbackColumnFunc, methodId, offset)) {
                data.push_back('?');
            }
            data.push_back(')');
            data.push_back('\n');
        } else if (needNative) {
            auto addr = method->GetNativePointer();
            std::stringstream strm;
            strm << addr;
            data.append("    at native method (").append(strm.str()).append(")\n");
        }
    }
    return data;
}
} // namespace panda::ecmascript
