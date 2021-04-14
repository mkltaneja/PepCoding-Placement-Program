// let a = 10;
// a = 20;
// console.log(a);

// var b = 10;
// b = 20
// console.log(b);

// console.log(c);
// const c = 10;
// c = 20

// function temp()
// {
//     let a = 0;
//     console.log(a);
//     {
//         let a = 10;
//         console.log(a);
//     }
//     {
//         var b = 10;
//     }
//     console.log(b);
//     {
//         var c = 10;
//     }
//     console.log(c);
// }


// let arr = [];
// arr[0] = 1;
// arr[2] = 3;
// arr.push(4);
// console.log(arr);
// arr.pop();
// console.log(arr);
// console.log(arr[1]);

// let arr2 = new Array(10)
// arr2[0] = 1
// console.log(arr2.length);


// arr = [1,2,3,4];
// for(let i = 0; i < arr.length; ++i){              // for loop
//     console.log(arr[i]);
// }

// arr = [1,2,3,4];
// for(let i in arr)                                  // for loop 2
//     console.log(i);

// arr = [1,2,3,4];
// arr.forEach(function(x, i){                        // for each loop
//     console.log(i, x+2);
// });


// let arr = [1,2,3,4]
// arr = arr.map(function(x, i){
//     return x+2;
// });
// console.log(arr);

// let arr = [1,2,3,4]
// arr = arr.map(function(i, x)
// {
//     if(i > 1)
//         return x+2;
//     return x;
// });
// console.log(arr);

// let arr = [1,2,3,4];
// delete arr[1];
// console.log(arr);

// let arr = [1,2,3,4];
// arr[6] = 0;
// arr["hello"] = "how are u?";
// console.log(arr.length)
// arr.splice(1,1);
// console.log(arr);

let obj = {
    "abc" : "hello",
    "abc" : "hello1",
    "abc1" : [1,2,3,4],
    "abc2" : function(){console.log("HELLO")},
    "abc3" : function(a){console.log(a)},
    1 : 123,
    2 : {
        "hello" : "how are u"
    },
}

// console.log(obj["abc1"]);
// console.log(Object.keys(obj));
// console.log(Object.values(obj));
console.log(Object.keys(obj).length);
