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

    DEBUG_HANDLE_OPCODE(LDNAN)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDNAN);
    }
    DEBUG_HANDLE_OPCODE(LDINFINITY)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDINFINITY);
    }
    DEBUG_HANDLE_OPCODE(LDUNDEFINED)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDUNDEFINED);
    }
    DEBUG_HANDLE_OPCODE(LDNULL)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDNULL);
    }
    DEBUG_HANDLE_OPCODE(LDSYMBOL)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDSYMBOL);
    }
    DEBUG_HANDLE_OPCODE(LDGLOBAL)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDGLOBAL);
    }
    DEBUG_HANDLE_OPCODE(LDTRUE)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDTRUE);
    }
    DEBUG_HANDLE_OPCODE(LDFALSE)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDFALSE);
    }
    DEBUG_HANDLE_OPCODE(LDHOLE)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDHOLE);
    }
    DEBUG_HANDLE_OPCODE(LDNEWTARGET)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDNEWTARGET);
    }
    DEBUG_HANDLE_OPCODE(POPLEXENV)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::POPLEXENV);
    }
    DEBUG_HANDLE_OPCODE(GETUNMAPPEDARGS)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETUNMAPPEDARGS);
    }
    DEBUG_HANDLE_OPCODE(ASYNCFUNCTIONENTER)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASYNCFUNCTIONENTER);
    }
    DEBUG_HANDLE_OPCODE(LDTHIS)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDTHIS);
    }
    DEBUG_HANDLE_OPCODE(LDFUNCTION)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDFUNCTION);
    }
    DEBUG_HANDLE_OPCODE(DEBUGGER)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEBUGGER);
    }
    DEBUG_HANDLE_OPCODE(GETPROPITERATOR)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETPROPITERATOR);
    }
    DEBUG_HANDLE_OPCODE(GETITERATOR_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETITERATOR_IMM8);
    }
    DEBUG_HANDLE_OPCODE(GETITERATOR_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETITERATOR_IMM16);
    }
    DEBUG_HANDLE_OPCODE(CLOSEITERATOR_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CLOSEITERATOR_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(CLOSEITERATOR_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CLOSEITERATOR_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(CREATEASYNCGENERATOROBJ_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEASYNCGENERATOROBJ_V8);
    }
    DEBUG_HANDLE_OPCODE(CREATEEMPTYOBJECT)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEEMPTYOBJECT);
    }
    DEBUG_HANDLE_OPCODE(CREATEEMPTYARRAY_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEEMPTYARRAY_IMM8);
    }
    DEBUG_HANDLE_OPCODE(CREATEEMPTYARRAY_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEEMPTYARRAY_IMM16);
    }
    DEBUG_HANDLE_OPCODE(CREATEGENERATOROBJ_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEGENERATOROBJ_V8);
    }
    DEBUG_HANDLE_OPCODE(CREATEITERRESULTOBJ_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEITERRESULTOBJ_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CREATEOBJECTWITHEXCLUDEDKEYS_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEOBJECTWITHEXCLUDEDKEYS_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(ASYNCGENERATORRESOLVE_V8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASYNCGENERATORRESOLVE_V8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CREATEARRAYWITHBUFFER_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEARRAYWITHBUFFER_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(CREATEARRAYWITHBUFFER_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEARRAYWITHBUFFER_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(CALLTHIS0_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLTHIS0_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(CALLTHIS1_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLTHIS1_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CREATEOBJECTWITHBUFFER_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEOBJECTWITHBUFFER_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(CREATEOBJECTWITHBUFFER_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEOBJECTWITHBUFFER_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(CREATEREGEXPWITHLITERAL_IMM8_ID16_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEREGEXPWITHLITERAL_IMM8_ID16_IMM8);
    }
    DEBUG_HANDLE_OPCODE(CREATEREGEXPWITHLITERAL_IMM16_ID16_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CREATEREGEXPWITHLITERAL_IMM16_ID16_IMM8);
    }
    DEBUG_HANDLE_OPCODE(NEWOBJAPPLY_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEWOBJAPPLY_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(NEWOBJAPPLY_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEWOBJAPPLY_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(NEWOBJRANGE_IMM8_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEWOBJRANGE_IMM8_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(NEWOBJRANGE_IMM16_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEWOBJRANGE_IMM16_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(NEWLEXENV_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEWLEXENV_IMM8);
    }
    DEBUG_HANDLE_OPCODE(NEWLEXENVWITHNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEWLEXENVWITHNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(ADD2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ADD2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(SUB2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SUB2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(MUL2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::MUL2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(DIV2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DIV2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(MOD2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::MOD2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(EQ_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::EQ_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(NOTEQ_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NOTEQ_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(LESS_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LESS_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(LESSEQ_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LESSEQ_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(GREATER_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GREATER_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(GREATEREQ_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GREATEREQ_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(SHL2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SHL2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(SHR2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SHR2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(ASHR2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASHR2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(AND2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::AND2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(OR2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::OR2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(XOR2_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::XOR2_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(EXP_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::EXP_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(TYPEOF_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TYPEOF_IMM8);
    }
    DEBUG_HANDLE_OPCODE(TYPEOF_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TYPEOF_IMM16);
    }
    DEBUG_HANDLE_OPCODE(TONUMBER_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TONUMBER_IMM8);
    }
    DEBUG_HANDLE_OPCODE(TONUMERIC_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TONUMERIC_IMM8);
    }
    DEBUG_HANDLE_OPCODE(NEG_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NEG_IMM8);
    }
    DEBUG_HANDLE_OPCODE(NOT_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NOT_IMM8);
    }
    DEBUG_HANDLE_OPCODE(INC_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::INC_IMM8);
    }
    DEBUG_HANDLE_OPCODE(DEC_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEC_IMM8);
    }
    DEBUG_HANDLE_OPCODE(ISIN_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ISIN_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(INSTANCEOF_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::INSTANCEOF_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(STRICTNOTEQ_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STRICTNOTEQ_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(STRICTEQ_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STRICTEQ_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(ISTRUE)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ISTRUE);
    }
    DEBUG_HANDLE_OPCODE(ISFALSE)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ISFALSE);
    }
    DEBUG_HANDLE_OPCODE(CALLTHIS2_IMM8_V8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLTHIS2_IMM8_V8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CALLTHIS3_IMM8_V8_V8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLTHIS3_IMM8_V8_V8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CALLTHISRANGE_IMM8_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLTHISRANGE_IMM8_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(SUPERCALLTHISRANGE_IMM8_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SUPERCALLTHISRANGE_IMM8_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(SUPERCALLARROWRANGE_IMM8_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SUPERCALLARROWRANGE_IMM8_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(DEFINEFUNC_IMM8_ID16_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINEFUNC_IMM8_ID16_IMM8);
    }
    DEBUG_HANDLE_OPCODE(DEFINEFUNC_IMM16_ID16_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINEFUNC_IMM16_ID16_IMM8);
    }
    DEBUG_HANDLE_OPCODE(DEFINEMETHOD_IMM8_ID16_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINEMETHOD_IMM8_ID16_IMM8);
    }
    DEBUG_HANDLE_OPCODE(CALLARG0_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLARG0_IMM8);
    }
    DEBUG_HANDLE_OPCODE(SUPERCALLSPREAD_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SUPERCALLSPREAD_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(APPLY_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::APPLY_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CALLARGS2_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLARGS2_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CALLARGS3_IMM8_V8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLARGS3_IMM8_V8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(CALLRANGE_IMM8_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLRANGE_IMM8_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(DEFINEMETHOD_IMM16_ID16_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINEMETHOD_IMM16_ID16_IMM8);
    }
    DEBUG_HANDLE_OPCODE(LDEXTERNALMODULEVAR_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDEXTERNALMODULEVAR_IMM8);
    }
    DEBUG_HANDLE_OPCODE(DEFINEGETTERSETTERBYVALUE_V8_V8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINEGETTERSETTERBYVALUE_V8_V8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(LDTHISBYNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDTHISBYNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDTHISBYNAME_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDTHISBYNAME_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(STTHISBYNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STTHISBYNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(STTHISBYNAME_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STTHISBYNAME_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDTHISBYVALUE_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDTHISBYVALUE_IMM8);
    }
    DEBUG_HANDLE_OPCODE(LDTHISBYVALUE_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDTHISBYVALUE_IMM16);
    }
    DEBUG_HANDLE_OPCODE(STTHISBYVALUE_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STTHISBYVALUE_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(STTHISBYVALUE_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STTHISBYVALUE_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(DEFINECLASSWITHBUFFER_IMM8_ID16_ID16_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINECLASSWITHBUFFER_IMM8_ID16_ID16_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(DEFINECLASSWITHBUFFER_IMM16_ID16_ID16_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DEFINECLASSWITHBUFFER_IMM16_ID16_ID16_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(RESUMEGENERATOR)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::RESUMEGENERATOR);
    }
    DEBUG_HANDLE_OPCODE(GETRESUMEMODE)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETRESUMEMODE);
    }
    DEBUG_HANDLE_OPCODE(GETTEMPLATEOBJECT_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETTEMPLATEOBJECT_IMM8);
    }
    DEBUG_HANDLE_OPCODE(GETTEMPLATEOBJECT_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETTEMPLATEOBJECT_IMM16);
    }
    DEBUG_HANDLE_OPCODE(GETNEXTPROPNAME_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETNEXTPROPNAME_V8);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQZ_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQZ_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQZ_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQZ_IMM16);
    }
    DEBUG_HANDLE_OPCODE(SETOBJECTWITHPROTO_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SETOBJECTWITHPROTO_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(DELOBJPROP_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DELOBJPROP_V8);
    }
    DEBUG_HANDLE_OPCODE(SUSPENDGENERATOR_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SUSPENDGENERATOR_V8);
    }
    DEBUG_HANDLE_OPCODE(ASYNCFUNCTIONAWAITUNCAUGHT_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASYNCFUNCTIONAWAITUNCAUGHT_V8);
    }
    DEBUG_HANDLE_OPCODE(COPYDATAPROPERTIES_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::COPYDATAPROPERTIES_V8);
    }
    DEBUG_HANDLE_OPCODE(STARRAYSPREAD_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STARRAYSPREAD_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(SETOBJECTWITHPROTO_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::SETOBJECTWITHPROTO_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(LDOBJBYVALUE_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDOBJBYVALUE_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(LDOBJBYVALUE_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDOBJBYVALUE_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(STOBJBYVALUE_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOBJBYVALUE_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(STOBJBYVALUE_IMM16_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOBJBYVALUE_IMM16_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYVALUE_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYVALUE_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYVALUE_IMM16_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYVALUE_IMM16_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(LDSUPERBYVALUE_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDSUPERBYVALUE_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(LDSUPERBYVALUE_IMM16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDSUPERBYVALUE_IMM16_V8);
    }
    DEBUG_HANDLE_OPCODE(STSUPERBYVALUE_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STSUPERBYVALUE_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(STSUPERBYVALUE_IMM16_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STSUPERBYVALUE_IMM16_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(LDOBJBYINDEX_IMM8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDOBJBYINDEX_IMM8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(LDOBJBYINDEX_IMM16_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDOBJBYINDEX_IMM16_IMM16);
    }
    DEBUG_HANDLE_OPCODE(STOBJBYINDEX_IMM8_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOBJBYINDEX_IMM8_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(STOBJBYINDEX_IMM16_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOBJBYINDEX_IMM16_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYINDEX_IMM8_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYINDEX_IMM8_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYINDEX_IMM16_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYINDEX_IMM16_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(ASYNCFUNCTIONRESOLVE_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASYNCFUNCTIONRESOLVE_V8);
    }
    DEBUG_HANDLE_OPCODE(ASYNCFUNCTIONREJECT_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASYNCFUNCTIONREJECT_V8);
    }
    DEBUG_HANDLE_OPCODE(COPYRESTARGS_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::COPYRESTARGS_IMM8);
    }
    DEBUG_HANDLE_OPCODE(LDLEXVAR_IMM4_IMM4)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDLEXVAR_IMM4_IMM4);
    }
    DEBUG_HANDLE_OPCODE(STLEXVAR_IMM4_IMM4)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STLEXVAR_IMM4_IMM4);
    }
    DEBUG_HANDLE_OPCODE(DYNAMICIMPORT)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::DYNAMICIMPORT);
    }
    DEBUG_HANDLE_OPCODE(ASYNCGENERATORREJECT_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::ASYNCGENERATORREJECT_V8);
    }
    DEBUG_HANDLE_OPCODE(GETMODULENAMESPACE_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::GETMODULENAMESPACE_IMM8);
    }
    DEBUG_HANDLE_OPCODE(STMODULEVAR_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STMODULEVAR_IMM8);
    }
    DEBUG_HANDLE_OPCODE(TRYLDGLOBALBYNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TRYLDGLOBALBYNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(TRYLDGLOBALBYNAME_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TRYLDGLOBALBYNAME_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(TRYSTGLOBALBYNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TRYSTGLOBALBYNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(TRYSTGLOBALBYNAME_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::TRYSTGLOBALBYNAME_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDGLOBALVAR_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDGLOBALVAR_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(STGLOBALVAR_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STGLOBALVAR_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDOBJBYNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDOBJBYNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDOBJBYNAME_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDOBJBYNAME_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(STOBJBYNAME_IMM8_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOBJBYNAME_IMM8_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(STOBJBYNAME_IMM16_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOBJBYNAME_IMM16_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYNAME_IMM8_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYNAME_IMM8_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYNAME_IMM16_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYNAME_IMM16_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(LDSUPERBYNAME_IMM8_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDSUPERBYNAME_IMM8_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDSUPERBYNAME_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDSUPERBYNAME_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(STSUPERBYNAME_IMM8_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STSUPERBYNAME_IMM8_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(STSUPERBYNAME_IMM16_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STSUPERBYNAME_IMM16_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(LDLOCALMODULEVAR_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDLOCALMODULEVAR_IMM8);
    }
    DEBUG_HANDLE_OPCODE(STCONSTTOGLOBALRECORD_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STCONSTTOGLOBALRECORD_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(STTOGLOBALRECORD_IMM16_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STTOGLOBALRECORD_IMM16_ID16);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQZ_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQZ_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQZ_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQZ_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JEQNULL_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQNULL_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JEQNULL_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQNULL_IMM16);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYVALUEWITHNAMESET_IMM8_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYVALUEWITHNAMESET_IMM8_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYVALUEWITHNAMESET_IMM16_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYVALUEWITHNAMESET_IMM16_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYNAMEWITHNAMESET_IMM8_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYNAMEWITHNAMESET_IMM8_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(STOWNBYNAMEWITHNAMESET_IMM16_ID16_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STOWNBYNAMEWITHNAMESET_IMM16_ID16_V8);
    }
    DEBUG_HANDLE_OPCODE(LDBIGINT_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDBIGINT_ID16);
    }
    DEBUG_HANDLE_OPCODE(LDA_STR_ID16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDA_STR_ID16);
    }
    DEBUG_HANDLE_OPCODE(JMP_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JMP_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JMP_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JMP_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JMP_IMM32)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JMP_IMM32);
    }
    DEBUG_HANDLE_OPCODE(JEQZ_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQZ_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JEQZ_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQZ_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JEQZ_IMM32)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQZ_IMM32);
    }
    DEBUG_HANDLE_OPCODE(JNEZ_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNEZ_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNEZ_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNEZ_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JNEZ_IMM32)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNEZ_IMM32);
    }
    DEBUG_HANDLE_OPCODE(JNENULL_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNENULL_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNENULL_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNENULL_IMM16);
    }
    DEBUG_HANDLE_OPCODE(LDA_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDA_V8);
    }
    DEBUG_HANDLE_OPCODE(STA_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STA_V8);
    }
    DEBUG_HANDLE_OPCODE(LDAI_IMM32)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDAI_IMM32);
    }
    DEBUG_HANDLE_OPCODE(FLDAI_IMM64)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::FLDAI_IMM64);
    }
    DEBUG_HANDLE_OPCODE(RETURN)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::RETURN);
    }
    DEBUG_HANDLE_OPCODE(RETURNUNDEFINED)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::RETURNUNDEFINED);
    }
    DEBUG_HANDLE_OPCODE(LDLEXVAR_IMM8_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::LDLEXVAR_IMM8_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQNULL_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQNULL_IMM8);
    }
    DEBUG_HANDLE_OPCODE(STLEXVAR_IMM8_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::STLEXVAR_IMM8_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQNULL_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQNULL_IMM16);
    }
    DEBUG_HANDLE_OPCODE(CALLARG1_IMM8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::CALLARG1_IMM8_V8);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQNULL_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQNULL_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQNULL_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQNULL_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JEQUNDEFINED_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQUNDEFINED_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JEQUNDEFINED_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQUNDEFINED_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JNEUNDEFINED_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNEUNDEFINED_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNEUNDEFINED_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNEUNDEFINED_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQUNDEFINED_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQUNDEFINED_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQUNDEFINED_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQUNDEFINED_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQUNDEFINED_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQUNDEFINED_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQUNDEFINED_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQUNDEFINED_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JEQ_V8_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQ_V8_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JEQ_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JEQ_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JNE_V8_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNE_V8_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNE_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNE_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQ_V8_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQ_V8_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JSTRICTEQ_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JSTRICTEQ_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQ_V8_IMM8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQ_V8_IMM8);
    }
    DEBUG_HANDLE_OPCODE(JNSTRICTEQ_V8_IMM16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::JNSTRICTEQ_V8_IMM16);
    }
    DEBUG_HANDLE_OPCODE(MOV_V4_V4)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::MOV_V4_V4);
    }
    DEBUG_HANDLE_OPCODE(MOV_V8_V8)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::MOV_V8_V8);
    }
    DEBUG_HANDLE_OPCODE(MOV_V16_V16)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::MOV_V16_V16);
    }
    DEBUG_HANDLE_OPCODE(NOP)
    {
        NOTIFY_DEBUGGER_EVENT();
        REAL_GOTO_DISPATCH_OPCODE(EcmaOpcode::NOP);
    }
    DEBUG_HANDLE_OPCODE(CALLRUNTIME)
    {
        NOTIFY_DEBUGGER_EVENT();
        DISPATCH_CALLRUNTIME();
    }
    DEBUG_HANDLE_OPCODE(DEPRECATED)
    {
        NOTIFY_DEBUGGER_EVENT();
        DISPATCH_DEPRECATED();
    }
    DEBUG_HANDLE_OPCODE(WIDE)
    {
        NOTIFY_DEBUGGER_EVENT();
        DISPATCH_WIDE();
    }
    DEBUG_HANDLE_OPCODE(THROW)
    {
        NOTIFY_DEBUGGER_EVENT();
        DISPATCH_THROW();
    }
    DEBUG_HANDLE_OPCODE(EXCEPTION)
    {
        NOTIFY_DEBUGGER_EXCEPTION_EVENT();
        REAL_GOTO_EXCEPTION_HANDLER();
    }
    DEBUG_HANDLE_OPCODE(OVERFLOW)
    {
        REAL_GOTO_DISPATCH_OPCODE(EXCEPTION_OPCODE + 1);
    }
