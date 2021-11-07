let arr = [1,2,3,4,5,6,7,8,9]

// let narr = [];
// for(let i = 0; i < arr.length; i++)
//     narr[i] = arr[i]*arr[i];

// OR By Using Map

let narr = arr.map(function(ele){
    return ele*ele; 
})

console.log(narr);