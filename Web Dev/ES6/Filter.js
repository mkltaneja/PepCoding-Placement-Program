let words = ["asfadsf", "asdfsda", "asfs", "sdasadsg", "awetrrewgsf", "sfs", "s"];

// let narr = [];
// for(let i = 0; i < words.length; i++)
// {
//     if(words[i].length > 6)
//         narr.push(words[i]);
// }

// OR Using Filter

let narr = words.filter(function(ele){
    return ele.length > 6;
})

console.log(narr);