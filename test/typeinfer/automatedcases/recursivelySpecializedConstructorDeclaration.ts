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

// === tests/cases/compiler/recursivelySpecializedConstructorDeclaration.ts ===
declare function AssertType(value:any, type:string):void;

module MsPortal.Controls.Base.ItemList {

    export interface Interface<TValue> {
        // Removing this line fixes the constructor of ItemValue
        options: ViewModel<TValue>;
    }    

    export class ItemValue<T> {
        constructor(value: T) {
        }
    }    
 
    export class ViewModel<TValue> extends ItemValue<TValue> {
    }
}

// Generates:
/*
declare module MsPortal.Controls.Base.ItemList {
    interface Interface<TValue> {
        options: ViewModel<TValue>;
    }
    class ItemValue<T> {
        constructor(value: T);
    }
    class ViewModel<TValue> extends ItemValue<TValue> {
    }
}
*/
