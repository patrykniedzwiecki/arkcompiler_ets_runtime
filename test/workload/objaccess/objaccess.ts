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

declare function print(arg:any):string;

class Animal {
    public name: string = "Animal";
    public age: number;

    sayHello() {
        
    }
}

class Dog extends Animal {
    age: number;

    constructor(age) {
        super();
        this.age = age;
    }
}

const dog = new  Dog(6);

var start = new Date().getTime();   
for (let i = 0; i < 1000000000; i++) {
    dog.sayHello();
    var age = dog.age;
    var s = dog.name;
}
var time = new Date().getTime() - start;
print(time);
