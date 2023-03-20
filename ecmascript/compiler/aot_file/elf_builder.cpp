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

#include "ecmascript/compiler/aot_file/elf_builder.h"

#include "ecmascript/ecma_macros.h"
#include "securec.h"

namespace panda::ecmascript {
void ElfBuilder::ModifyStrTabSection()
{
    bool existedStrTab = false;
    uint64_t strTabAddr = 0;
    uint32_t strTabSize = 0;
    std::vector<std::string> sectionNames;
    std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    // modify strtab
    for (auto &s : sections) {
        if (s.first == ElfSecName::STRTAB) {
            existedStrTab = true;
            strTabAddr = s.second.first;
            strTabSize = s.second.second;
            break;
        }
    }

    for (auto &s : sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        auto str = sectionDes_.GetSecName(s.first);
        llvm::ELF::Elf64_Word id = FindShName(str, strTabAddr, strTabSize);
        if (id == static_cast<llvm::ELF::Elf64_Word>(-1)) {
            sectionNames.emplace_back(str);
        }
    }
    uint32_t size = 0;
    if (existedStrTab) {
        size += strTabSize;
    }
    for (auto &str: sectionNames) {
        size = size + str.size() + 1;
    }
    strTabPtr_ = std::make_unique<char []>(size);
    char *dst = strTabPtr_.get();
    if (strTabSize > 0) {
        if ((memcpy_s(dst, size, reinterpret_cast<char *>(strTabAddr), strTabSize)) != EOK) {
            UNREACHABLE();
        }
    }
    uint32_t i = strTabSize;
    for (auto &str: sectionNames) {
        uint32_t copySize = str.size();
        if (copySize == 0) {
            UNREACHABLE();
        }
        if ((copySize != 0) && ((memcpy_s(dst + i, size - i + 1, str.data(), copySize)) != EOK)) {
            UNREACHABLE();
        }
        dst[i + copySize] = 0x0;
        i = i + copySize + 1;
    }

    if (existedStrTab) {
        sections.erase(ElfSecName::STRTAB);
    }
    sections[ElfSecName::STRTAB] = std::make_pair(reinterpret_cast<uint64_t>(strTabPtr_.get()), size);
    [[maybe_unused]] uint32_t symtabSize = sections[ElfSecName::SYMTAB].second;
    ASSERT(symtabSize % sizeof(llvm::ELF::Elf64_Sym) == 0);
    if (enableSecDump_) {
        DumpSection();
    }
}

void ElfBuilder::DumpSection() const
{
    const std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    // dump
    for (auto &s : sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        LOG_COMPILER(INFO) << "secname :" << std::dec << static_cast<int>(s.first)
            << " addr:0x" << std::hex << s.second.first << " size:0x" << s.second.second << std::endl;
    }
}

void ElfBuilder::AddArkStackMapSection()
{
    // add arkstackmap
    std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    std::shared_ptr<uint8_t> ptr = sectionDes_.GetArkStackMapSharePtr();
    uint64_t arkStackMapAddr = reinterpret_cast<uint64_t>(ptr.get());
    uint32_t arkStackMapSize = sectionDes_.arkStackMapSize_;
    if (arkStackMapSize > 0) {
        sections[ElfSecName::ARK_STACKMAP] = std::pair(arkStackMapAddr, arkStackMapSize);
    }
}

ElfBuilder::ElfBuilder(ModuleSectionDes sectionDes): sectionDes_(sectionDes)
{
    AddArkStackMapSection();
    ModifyStrTabSection();
    sectionToAlign_ = {
        {ElfSecName::RODATA, 8},
        {ElfSecName::RODATA_CST4, 8},
        {ElfSecName::RODATA_CST8, 8},
        {ElfSecName::RODATA_CST16, 8},
        {ElfSecName::RODATA_CST32, 8},
        {ElfSecName::TEXT, 16},
        {ElfSecName::STRTAB, 1},
        {ElfSecName::SYMTAB, 8},
        {ElfSecName::ARK_STACKMAP, 8},
        {ElfSecName::ARK_FUNCENTRY, 8},
    };

    sectionToSegment_ = {
        {ElfSecName::RODATA, ElfSecName::TEXT},
        {ElfSecName::RODATA_CST4, ElfSecName::TEXT},
        {ElfSecName::RODATA_CST8, ElfSecName::TEXT},
        {ElfSecName::RODATA_CST16, ElfSecName::TEXT},
        {ElfSecName::RODATA_CST32, ElfSecName::TEXT},
        {ElfSecName::TEXT, ElfSecName::TEXT},
        {ElfSecName::STRTAB, ElfSecName::DATA},
        {ElfSecName::SYMTAB, ElfSecName::DATA},
        {ElfSecName::ARK_STACKMAP, ElfSecName::DATA},
        {ElfSecName::ARK_FUNCENTRY, ElfSecName::DATA},
    };

    segmentToFlag_ = {
        {ElfSecName::TEXT, llvm::ELF::PF_X | llvm::ELF::PF_R},
        {ElfSecName::DATA, llvm::ELF::PF_R},
    };
}

ElfBuilder::~ElfBuilder()
{
    strTabPtr_ = nullptr;
}

llvm::ELF::Elf64_Half ElfBuilder::GetShStrNdx(std::map<ElfSecName, std::pair<uint64_t, uint32_t>>& sections) const
{
    llvm::ELF::Elf64_Half shstrndx = 1; // skip null section
    for (auto &s : sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        if (s.first == ElfSecName::STRTAB) {
            return shstrndx;
        }
        shstrndx++;
    }
    UNREACHABLE();
}

llvm::ELF::Elf64_Half ElfBuilder::GetSecSize() const
{
    llvm::ELF::Elf64_Half secsSize = 0;
    const std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    for (auto &s : sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        uint32_t curSecSize = sectionDes_.GetSecSize(s.first);
        secsSize += curSecSize;
    }
    return secsSize;
}

int ElfBuilder::GetSecNum() const
{
    int secNum = 0;
    const std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    for (auto &s : sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        ++secNum;
    }
    return secNum;
}

/*
ELF Header as follow:
ELF Header:
  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00
  Class:                             ELF64
  Data:                              2's complement, little endian
  Version:                           1
  OS/ABI:                            UNIX - System V
  ABI Version:                       0
  Type:                              DYN (Shared object file)
  Machine:                           Advanced Micro Devices X86-64
  Version:                           0x2
  Entry point address:               0x0
  Start of program headers:          20480 (bytes into file)
  Start of section headers:          64 (bytes into file)
  Flags:                             0x0
  Size of this header:               64 (bytes)
  Size of program headers:           56 (bytes)
  Number of program headers:         2
  Size of section headers:           64 (bytes)
  Number of section headers:         7
  Section header string table index: 3
There are 7 section headers, starting at offset 0x40:
*/
void ElfBuilder::PackELFHeader(llvm::ELF::Elf64_Ehdr &header, uint32_t version, Triple triple)
{
    if (memset_s(reinterpret_cast<void *>(&header), sizeof(llvm::ELF::Elf64_Ehdr), 0, sizeof(llvm::ELF::Elf64_Ehdr)) != EOK) {
        UNREACHABLE();
    }
    header.e_ident[llvm::ELF::EI_MAG0] = llvm::ELF::ElfMagic[llvm::ELF::EI_MAG0];
    header.e_ident[llvm::ELF::EI_MAG1] = llvm::ELF::ElfMagic[llvm::ELF::EI_MAG1];
    header.e_ident[llvm::ELF::EI_MAG2] = llvm::ELF::ElfMagic[llvm::ELF::EI_MAG2];
    header.e_ident[llvm::ELF::EI_MAG3] = llvm::ELF::ElfMagic[llvm::ELF::EI_MAG3];
    header.e_ident[llvm::ELF::EI_CLASS] = llvm::ELF::ELFCLASS64;
    header.e_ident[llvm::ELF::EI_DATA] = llvm::ELF::ELFDATA2LSB;
    header.e_ident[llvm::ELF::EI_VERSION] = 1;

    header.e_type = llvm::ELF::ET_DYN;
    switch (triple) {
        case Triple::TRIPLE_AMD64:
            header.e_machine = llvm::ELF::EM_X86_64;
            break;
        case Triple::TRIPLE_ARM32:
            header.e_machine = llvm::ELF::EM_ARM;
            break;
        case Triple::TRIPLE_AARCH64:
            header.e_machine = llvm::ELF::EM_AARCH64;
            break;
        default:
            UNREACHABLE();
            break;
    }
    header.e_version = version;
    std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    // start of section headers
    header.e_shoff = sizeof(llvm::ELF::Elf64_Ehdr);
    // size of ehdr
    header.e_ehsize = sizeof(llvm::ELF::Elf64_Ehdr);
    // size of section headers
    header.e_shentsize = sizeof(llvm::ELF::Elf64_Shdr);
    // number of section headers
    header.e_shnum = GetSecNum() + 1; // 1: skip null section and ark stackmap
    // section header string table index
    header.e_shstrndx = GetShStrNdx(sections);
    // phr
    header.e_phentsize = sizeof(llvm::ELF::Elf64_Phdr);
    header.e_phnum = GetSegmentNum();
}

int ElfBuilder::GetSegmentNum() const
{
    const std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    std::set<ElfSecName> segments;
    for (auto &s: sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        auto it = sectionToSegment_.find(s.first);
        ASSERT(it != sectionToSegment_.end());
        ElfSecName name = it->second;
        segments.insert(name);
    }
    return segments.size();
}

ElfSecName ElfBuilder::FindLastSection(ElfSecName segment) const
{
    ElfSecName ans = ElfSecName::NONE;
    const std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    for (auto &s: sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        auto it = sectionToSegment_.find(s.first);
        ASSERT(it != sectionToSegment_.end());
        ElfSecName name = it->second;
        if (name != segment) {
            continue;
        }
        ans = std::max(ans, s.first);
    }
    return ans;
}

llvm::ELF::Elf64_Word ElfBuilder::FindShName(std::string name, uintptr_t strTabPtr, int strTabSize)
{
    llvm::ELF::Elf64_Word ans = -1;
    int len = name.size();
    if (strTabSize < len + 1) {
        return ans;
    }
    LOG_ECMA(DEBUG) << "  FindShName name:" << name.c_str() << std::endl;
    for (int i = 0; i < strTabSize - len + 1; ++i) {
        char *dst = reinterpret_cast<char *>(strTabPtr) + i;
        if (name.compare(dst) == 0) {
            return i;
        }
    }
    return ans;
}

std::pair<uint64_t, uint32_t> ElfBuilder::FindStrTab() const
{
    const std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    uint64_t strTabAddr = 0;
    uint32_t strTabSize = 0;
    for (auto &s: sections) {
        uint32_t curSecSize = sectionDes_.GetSecSize(s.first);
        uint64_t curSecAddr = sectionDes_.GetSecAddr(s.first);
        if (s.first == ElfSecName::STRTAB) {
            strTabSize = curSecSize;
            strTabAddr = curSecAddr;
            break;
        }
    }
    return std::make_pair(strTabAddr, strTabSize);
}

/*
section layout as follows:
Section Headers:
  [Nr] Name              Type            Address          Off    Size   ES Flg Lk Inf Al
  [ 0]                   NULL            0000000000000000 000000 000000 00      0   0  0
  [ 1] .rodata.cst8      PROGBITS        0000000000001000 001000 000020 00  AM  0   0  8
  [ 2] .text             PROGBITS        0000000000001020 001020 001130 00  AX  0   0 16
  [ 3] .strtab           STRTAB          0000000000003000 003000 0001a5 00   A  0   0  1
  [ 4] .symtab           SYMTAB          00000000000031a8 0031a8 0001c8 18   A  1   0  8
  [ 5] .ark_funcentry    PROGBITS        0000000000003370 003370 0006c0 00   A  0   0  8
  [ 6] .ark_stackmaps    PROGBITS        0000000000003a30 003a30 0010f5 00   A  0   0  8
*/
void ElfBuilder::PackELFSections(std::ofstream &file)
{
    std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    uint32_t secNum = sections.size() + 1; // 1 : section id = 0 is null section
    std::unique_ptr<llvm::ELF::Elf64_Shdr []> shdr = std::make_unique<llvm::ELF::Elf64_Shdr []>(secNum);
    if (memset_s(reinterpret_cast<void *>(&shdr[0]), sizeof(llvm::ELF::Elf64_Shdr), 0, sizeof(llvm::ELF::Elf64_Shdr)) != EOK) {
        UNREACHABLE();
    }

    llvm::ELF::Elf64_Off curSecOffset = sizeof(llvm::ELF::Elf64_Ehdr) + secNum * sizeof(llvm::ELF::Elf64_Shdr);
    curSecOffset = AlignUp(curSecOffset, PageSize()); // not pagesize align will cause performance degradation
    file.seekp(curSecOffset);

    int i = 1; // 1: skip null section
    auto strTab = FindStrTab();

    for (auto &s: sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        shdr[i].sh_addralign = sectionToAlign_[s.first];
        if (curSecOffset % shdr[i].sh_addralign != 0) {
            curSecOffset = AlignUp(curSecOffset, shdr[i].sh_addralign);
            file.seekp(curSecOffset);
        }
        auto it = sectionToSegment_.find(s.first);
        ASSERT(it != sectionToSegment_.end());
        ElfSecName segName = it->second;
        segments_.insert(segName);
        uint32_t curSecSize = sectionDes_.GetSecSize(s.first);
        uint64_t curSecAddr = sectionDes_.GetSecAddr(s.first);
        std::string secName = sectionDes_.GetSecName(s.first);
        // text section address needs 16 bytes alignment
        if ((ElfSecName::RODATA <= s.first && s.first <= ElfSecName::RODATA_CST8) || s.first == ElfSecName::TEXT) {
            curSecOffset = AlignUp(curSecOffset, TEXT_SEC_ALIGN);
            file.seekp(curSecOffset);
        }
        sectionToFileOffset_[s.first] = file.tellp();
        file.write(reinterpret_cast<char *>(curSecAddr), curSecSize);
        llvm::ELF::Elf64_Word shName = FindShName(secName, strTab.first, strTab.second);
        ASSERT(shName != static_cast<llvm::ELF::Elf64_Word>(-1));
        shdr[i].sh_name = shName;
        shdr[i].sh_type = section.Type();
        shdr[i].sh_flags = section.Flag();
        shdr[i].sh_addr = curSecOffset;
        shdr[i].sh_offset = curSecOffset;
        LOG_COMPILER(DEBUG) << "curSecOffset:   0x" << std::hex << curSecOffset << "  curSecSize:0x" << curSecSize;
        curSecOffset += curSecSize;
        ElfSecName lastSecName = FindLastSection(segName);
        if (s.first == lastSecName) {
            curSecOffset = AlignUp(curSecOffset, PageSize());
            file.seekp(curSecOffset);
        }
        shdr[i].sh_size = curSecSize;
        shdr[i].sh_link = section.Link();
        shdr[i].sh_info = 0;
        shdr[i].sh_entsize = section.Entsize();
        sectionToShdr_[s.first] = shdr[i];
        LOG_COMPILER(DEBUG) << "  shdr[i].sh_entsize " << std::hex << shdr[i].sh_entsize << std::endl;
        ++i;
    }
    uint32_t secEnd = file.tellp();
    file.seekp(sizeof(llvm::ELF::Elf64_Ehdr));
    file.write(reinterpret_cast<char *>(shdr.get()), secNum * sizeof(llvm::ELF::Elf64_Shdr));
    file.seekp(secEnd);
}

unsigned ElfBuilder::GetPFlag(ElfSecName segment) const
{
    return segmentToFlag_.at(segment);
}

/*
segment layout as follows:
Program Headers:
  Type           Offset   VirtAddr           PhysAddr           FileSiz  MemSiz   Flg Align
  LOAD           0x001000 0x0000000000001000 0x0000000000001000 0x001150 0x002000 R E 0x1000
  LOAD           0x003000 0x0000000000003000 0x0000000000003000 0x001b25 0x002000 R   0x1000

 Section to Segment mapping:
  Segment Sections...
   00     .rodata.cst8 .text
   01     .strtab .symtab .ark_funcentry .ark_stackmaps
   None
*/
void ElfBuilder::PackELFSegment(std::ofstream &file)
{
    llvm::ELF::Elf64_Off e_phoff = file.tellp();
    long phoff = (long)offsetof(struct llvm::ELF::Elf64_Ehdr, e_phoff);
    // write Elf32_Off e_phoff
    file.seekp(phoff);
    file.write(reinterpret_cast<char *>(&e_phoff), sizeof(e_phoff));
    file.seekp(e_phoff);

    int segNum = GetSegmentNum();
    auto phdrs = std::make_unique<llvm::ELF::Elf64_Phdr []>(segNum);
    std::map<ElfSecName, llvm::ELF::Elf64_Off> segmentToMaxOffset;
    std::map<ElfSecName, llvm::ELF::Elf64_Off> segmentToMaxAddress;
    std::set<ElfSecName> segments;
    // SecName -> addr & size
    std::map<ElfSecName, std::pair<uint64_t, uint32_t>> &sections = sectionDes_.sectionsInfo_;
    llvm::ELF::Elf64_Off offset = e_phoff;
    for (auto &s: sections) {
        ElfSection section = ElfSection(s.first);
        if (!section.ShouldDumpToAOTFile()) {
            continue;
        }
        auto it = sectionToSegment_.find(s.first);
        ASSERT(it != sectionToSegment_.end());
        ElfSecName segName = it->second;
        segments.insert(segName);
        if (segmentToMaxOffset.find(segName) == segmentToMaxOffset.end()) {
            segmentToMaxOffset[segName] = 0;
        }
        segmentToMaxOffset[segName] =
            std::max(segmentToMaxOffset[segName], sectionToShdr_[s.first].sh_offset + sectionToShdr_[s.first].sh_size);
        segmentToMaxAddress[segName] =
            std::max(segmentToMaxAddress[segName], sectionToShdr_[s.first].sh_addr + sectionToShdr_[s.first].sh_size);
        offset = std::min(offset, sectionToShdr_[s.first].sh_offset);
    }
    int phdrIndex = 0;
    llvm::ELF::Elf64_Addr addr = offset;
    for (auto &it: segments) {
        ElfSecName name = it;
        phdrs[phdrIndex].p_align = PageSize();
        phdrs[phdrIndex].p_type = llvm::ELF::PT_LOAD;
        phdrs[phdrIndex].p_flags = GetPFlag(name);
        offset = AlignUp(offset, PageSize());
        phdrs[phdrIndex].p_offset = offset;
        phdrs[phdrIndex].p_vaddr = addr % phdrs[phdrIndex].p_align == 0 ?
            addr : (addr / phdrs[phdrIndex].p_align + 1) * phdrs[phdrIndex].p_align;
        phdrs[phdrIndex].p_paddr = phdrs[phdrIndex].p_vaddr;

        phdrs[phdrIndex].p_filesz = segmentToMaxOffset[name] - phdrs[phdrIndex].p_offset;
        phdrs[phdrIndex].p_memsz = segmentToMaxAddress[name] - phdrs[phdrIndex].p_vaddr;
        phdrs[phdrIndex].p_memsz = AlignUp(phdrs[phdrIndex].p_memsz, PageSize());
        addr = phdrs[phdrIndex].p_vaddr + phdrs[phdrIndex].p_memsz;
        offset += phdrs[phdrIndex].p_filesz;
        ++phdrIndex;
    }
    file.write(reinterpret_cast<char *>(phdrs.get()), sizeof(llvm::ELF::Elf64_Phdr) * segNum);
}
}  // namespace panda::ecmascript
