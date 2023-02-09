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

#include "ecmascript/platform/file.h"

#include <cerrno>
#include <climits>
#include <sys/mman.h>
#include <unistd.h>

#include "ecmascript/log_wrapper.h"
#include "ecmascript/platform/map.h"

namespace panda::ecmascript {
std::string GetFileDelimiter()
{
    return ":";
}

bool RealPath(const std::string &path, std::string &realPath, bool readOnly)
{
    if (path.empty() || path.size() > PATH_MAX) {
        LOG_ECMA(WARN) << "File path is illeage";
        return false;
    }
    char buffer[PATH_MAX] = { '\0' };
    if (!realpath(path.c_str(), buffer)) {
        // Maybe file does not exist.
        if (!readOnly && errno == ENOENT) {
            realPath = path;
            return true;
        }
        LOG_ECMA(ERROR) << "File path:" << path << " realpath failure";
        return false;
    }
    realPath = std::string(buffer);
    return true;
}

void DPrintf(fd_t fd, const std::string &buffer)
{
    int ret = dprintf(fd, "%s", buffer.c_str());
    if (ret < 0) {
        LOG_ECMA(DEBUG) << "dprintf fd(" << fd << ") failed";
    }
}

void FSync(fd_t fd)
{
    int ret = fsync(fd);
    if (ret < 0) {
        LOG_ECMA(DEBUG) << "fsync fd(" << fd << ") failed";
    }
}

void Close(fd_t fd)
{
    close(fd);
}

MemMap FileMap(const char *fileName, int flag, int prot, int64_t offset)
{
    fd_t fd = open(fileName, flag);
    if (fd == INVALID_FD) {
        LOG_ECMA(ERROR) << fileName << " file open failed";
        return MemMap();
    }

    size_t size = lseek(fd, 0, SEEK_END);
    if (size <= 0) {
        close(fd);
        LOG_ECMA(ERROR) << fileName << " file is empty";
        return MemMap();
    }

    void *addr = mmap(nullptr, size, prot, MAP_PRIVATE, fd, offset);
    close(fd);
    return MemMap(addr, size);
}

int FileUnMap(MemMap addr)
{
    return munmap(addr.GetOriginAddr(), addr.GetSize());
}
}  // namespace panda::ecmascript
