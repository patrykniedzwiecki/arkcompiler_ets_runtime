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

// === tests/cases/conformance/types/typeRelationships/typeAndMemberIdentity/objectTypesIdentityWithGenericCallSignaturesDifferingByConstraints3.ts ===
declare function AssertType(value:any, type:string):void;
// Two call or construct signatures are considered identical when they have the same number of type parameters and, considering those 
// parameters pairwise identical, have identical type parameter constraints, identical number of parameters with identical kind(required, 
// optional or rest) and types, and identical return types.

class One { foo: string }
class Two { foo: string }
interface Three { foo: string }
interface Four<T> { foo: T }
interface Five<T> extends Four<T> { }
interface Six<T, U> {
    foo: T;
}

class A {
    foo<T extends U, U extends One>(x: T, y: U): string { 
AssertType(null, "null");
return null; 
}
}

class B<T extends U, U extends Two> {
    foo(x: T, y: U): string { 
AssertType(null, "null");
return null; 
}
}

class C<T extends U, U extends Three> {
    foo(x: T, y: U): string { 
AssertType(null, "null");
return null; 
}
}

class D<T extends U, U extends Four<string>> {
    foo(x: T, y: U): string { 
AssertType(null, "null");
return null; 
}
}

interface I<T extends U, U extends Five<string>> {
    foo(x: T, y: U): string;
}

interface I2 {
    foo<T extends U, U extends Six<string, string>>(x: T, y: U): string;
}

let a: { foo<T extends U, U extends One>(x: T, y: U): string 
AssertType(a, "{ foo<T extends U, U extends One>(T, U): string; }");

AssertType(foo, "<T extends U, U extends One>(T, U) => string");

AssertType(x, "T");

AssertType(y, "U");
}

let b = { foo<T extends U, U extends Two>(x: T, y: U) { 
AssertType(b, "{ foo<T extends U, U extends Two>(T, U): string; }");
AssertType({ foo<T extends U, U extends Two>(x: T, y: U) { return ''; } }, "{ foo<T extends U, U extends Two>(T, U): string; }");
AssertType(foo, "<T extends U, U extends Two>(T, U) => string");
AssertType(x, "T");
AssertType(y, "U");
AssertType('', "string");
return ''; } };

function foo1(x: A);
function foo1(x: A); // error
function foo1(x: any) { }

function foo1b(x: B<Two, Two>);
function foo1b(x: B<Two, Two>); // error
function foo1b(x: any) { }

function foo1c(x: C<Three, Three>);
function foo1c(x: C<Three, Three>); // error
function foo1c(x: any) { }

function foo2(x: I<Five<string>, Five<string>>);
function foo2(x: I<Five<string>, Five<string>>); // error
function foo2(x: any) { }

function foo3(x: typeof a);
function foo3(x: typeof a); // error
function foo3(x: any) { }

function foo4(x: typeof b);
function foo4(x: typeof b); // error
function foo4(x: any) { }

function foo5(x: A);
function foo5(x: B<Two, Two>); // ok
function foo5(x: any) { }

function foo5b(x: A);
function foo5b(x: C<Three, Three>); // ok
function foo5b(x: any) { }

function foo5c(x: C<Three, Three>);
function foo5c(x: D<Four<string>, Four<string>>); // error
function foo5c(x: any) { }

function foo6c(x: C<Three, Three>);
function foo6c(x: D<Four<string>, Four<string>>); // error
function foo6c(x: any) { }

function foo6(x: A);
function foo6(x: I<Five<string>, Five<string>>); // ok
function foo6(x: any) { }

function foo7(x: A);
function foo7(x: typeof a); // error
function foo7(x: any) { }

function foo8(x: B<Two, Two>);
function foo8(x: I<Five<string>, Five<string>>); // error
function foo8(x: any) { }

function foo9(x: B<Two, Two>);
function foo9(x: C<Three, Three>); // error
function foo9(x: any) { }

function foo10(x: B<Two, Two>);
function foo10(x: typeof a); // ok
function foo10(x: any) { }

function foo11(x: B<Two, Two>);
function foo11(x: typeof b); // ok
function foo11(x: any) { }

function foo12(x: I<Five<string>, Five<string>>);
function foo12(x: C<Three, Three>); // error
function foo12(x: any) { }

function foo12b(x: I2);
function foo12b(x: C<Three, Three>); // ok
function foo12b(x: any) { }

function foo13(x: I<Five<string>, Five<string>>);
function foo13(x: typeof a); // ok
function foo13(x: any) { }

function foo14(x: I<Five<string>, Five<string>>);
function foo14(x: typeof b); // ok
function foo14(x: any) { }

function foo15(x: I2);
function foo15(x: C<Three, Three>); // ok
function foo15(x: any) { }
