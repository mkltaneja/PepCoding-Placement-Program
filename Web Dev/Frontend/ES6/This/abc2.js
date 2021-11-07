// function fn()
// {
//     console.log(`Hi! My name is ${this.person}`);
//     function abc()
//     {
//         console.log(`Hi! My name is ${this.person}`);
//     }
//     abc();
// }

// // fn();

// let obj = {
//     person: "Mukul",
//     func: fn
// }

// obj.func();
// // Output: 
// // Hi! My name is Mukul
// // Hi! My name is undefined






//////////// How to get "Mukul" instead of "undefined"? =============

// Solution 1 -> Using "bind" ----------------
// Bind is a function that is defined on other functions 
// let ret = fn.bind(argument);
// bind returns a new function whose definition is similar to the function on which it is called
// and whose "this" is explicitly set to the argument that is passed

function fn()
{
    console.log(`Hi! My name is ${this.person}`);
    function abc()
    {
        console.log(`Hi! My name is ${this.person}`);
    }
    let ret = abc.bind(this);
    // ret();  // Will not print undefined now, but will print "Mukul"
    return ret;
}

// fn();

let obj = {
    person: "Mukul",
    func: fn
}

// obj.func();
let rf = obj.func();
rf();
// Output: 
// Hi! My name is Mukul
// Hi! My name is Mukul
