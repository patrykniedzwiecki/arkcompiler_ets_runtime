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

// === tests/cases/compiler/es6ModuleConstEnumDeclaration.ts ===
declare function AssertType(value:any, type:string):void;
export const enum e1 {
    a,
    b,
    c
}
const enum e2 {
    x,
    y,
    z
}
let x = e1.a;
AssertType(x, "e1");
AssertType(e1.a, "e1.a");

let y = e2.x;
AssertType(y, "e2");
AssertType(e2.x, "e2.x");

export module m1 {
    export const enum e3 {
        a,
        b,
        c
    }
    const enum e4 {
        x,
        y,
        z
    }
    let x1 = e1.a;
    let y1 = e2.x;
    let x2 = e3.a;
    let y2 = e4.x;
}
module m2 {
    export const enum e5 {
        a,
        b,
        c
    }
    const enum e6 {
        x,
        y,
        z
    }
    let x1 = e1.a;
    let y1 = e2.x;
    let x2 = e5.a;
    let y2 = e6.x;
    let x3 = m1.e3.a;
}
