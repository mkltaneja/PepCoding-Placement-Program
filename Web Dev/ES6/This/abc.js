// "this" is a keyword that refers to an object
// The value of "this" would change according to the context in which it is being referred to

// If "this" is not referring to anything, then it refers to the window
console.log(this);




function fn()
{
    console.log(typeof(this));
    console.log(this);
    console.log(`Hi! My name is ${this.person}`);
}




// Normal call -> this = window
// Undefined

// fn();

let obj = {
    person: "Mukul",
    func: fn
}




// Function call with object -> this = obj (object through which fn is called)

// Mukul
// obj.func();



// this = window (As ret points to the adress of the function in the heap, so when it is called it has nothing bind with it)

// Undefined
let ret = obj.func;
ret();