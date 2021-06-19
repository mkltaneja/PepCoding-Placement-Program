// class abc
// {
//     constructor(person)
//     {
//         this.person = person;
//         this.age = 20;
//         this.sayHi2 = this.sayHi.bind(this);
//     }
//     sayHi()
//     {
//         console.log("Hello");
//         console.log(this.person);
//     }
// }

// let obj = new abc("Mukul");

// // console.log(obj);

// // NOTE:-  [EXCEPTION here:- window object will not be printed now as for class member functions, by default the value is undefined in a normal call]
// // let fn = obj.sayHi;
// // fn();
// // Output -> Undefined


// // Solution 1 -> "bind"

// let btn = document.querySelector("button");
// btn.addEventListener("click", obj.sayHi2);
// Output -> Hello Mukul [So undefined can be removeed in classes by using bind]








// Soution 2 -> Arrow Function (=>)

// Note :-> In an arrow function, this points to the lexical content (which is just outside the current scope)

class abc
{
    constructor(person)
    {
        this.person = person;
        this.age = 20;
    }
    sayHi=()=>{
        console.log("Hello");
        console.log(this.person);
    }
}

let obj = new abc("Mukul");

// console.log(obj);

// NOTE:-  [EXCEPTION here:- window object will not be printed now as for class member functions, by default the value is undefined in a normal call]
// let fn = obj.sayHi;
// fn();
// Output -> Undefined


let btn = document.querySelector("button");
btn.addEventListener("click", obj.sayHi);