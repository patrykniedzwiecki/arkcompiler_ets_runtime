/*
* Copyright (c) Microsoft Corporation. All rights reserved.
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
*
* This file has been modified by Huawei to verify type inference by adding verification statements.
*/

// === tests/cases/compiler/collisionSuperAndPropertyNameAsConstuctorParameter.ts ===
declare function AssertType(value:any, type:string):void;
class a {
}

class b1 extends a {
    constructor(_super: number) { // should be error
        super();
AssertType(super(), "void");
AssertType(super, "typeof a");
    }
}

class b2 extends a {
    constructor(private _super: number) { // should be error
        super();
AssertType(super(), "void");
AssertType(super, "typeof a");
    }
}

class b3 extends a {
    constructor(_super: number); // no code gen - no error
    constructor(_super: string);// no code gen - no error
    constructor(_super: any) { // should be error
        super();
AssertType(super(), "void");
AssertType(super, "typeof a");
    }
}

class b4 extends a {
    constructor(_super: number); // no code gen - no error
    constructor(_super: string);// no code gen - no error
    constructor(private _super: any) { // should be error
        super();
AssertType(super(), "void");
AssertType(super, "typeof a");
    }
}
