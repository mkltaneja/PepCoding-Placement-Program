
// ANS 1

// // let cmds = process.argv.splice(2);
// // const fs = require("fs");


// let ans = [];
// // console.log(Object.keys(ans[1]).length);
// function flatten(obj, str)
// {
//     let l = Object.keys(obj).length;
//     console.log(l);
//     if(l > 0)
//     {
//         for(let k of Object.keys(obj))
//         {
//             flatten(k, str+k+".");
//         }
//     }
//     else 
//     {
//         // console.log(str);
//         if(str.length > 0)
//             str.slice(0, -1);
//         // var temp = {};
//         var temp = {str : obj["str"]};
//         ans.push(temp);
//         return;
//     }
//     return;
// }

// let object = {
//     newObj: {
//         obj2: {
//             obj5: {
//                 one: 1,
//             },
//         },
//     },
//     obj3: {
//         obj4: {
//             two: 2
//         },
//     },
// };
// flatten(object, "");

// for(let x in ans)
//     console.log(ans[x]);



// ANS 2

let file = process.argv[2];
const fs = require("fs");
let data = fs.readFileSync(file, "utf-8");
