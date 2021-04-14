// function rainDance(object, name, rainfall)
// {
//     let arr;
//     for(let obj in Object.keys(object))
//     {
//         let avg = 0;
//         for(let x in rainfall)
//             avg += x;
//         avg /= rainfall.length;
//         arr[object[name]] = avg;
//     }
// }

let input1 = [
    { name: "Delhi", rainfall: [2.3, 4, 3.1, 5.5, 1.1, 1.2, 7] },
    { name: "Noida", rainfall: [6.3, 0, 0.1, 3.5, 1, 2.6, 0.7] },
    { name: "Dehradun", rainfall: [12, 5.6, 3.1, 0.55, 11, 16.2, 19] },
    { name: "Nanital", rainfall: [8, 1.4, 0.61, 15.5, 6.6, 2, 9.82] },
];

// for(let i in input1)
// {
//     let avg = 0;
//     for(let j in input1[i]["rainfall"])
//         avg += input1[i][j];
//     avg /= input1[i].length;
//     delete input1[i]["rainfall"];
//     input1[i]["avgRainfall"] = avg;
// }

console.log(Object.values(input1));