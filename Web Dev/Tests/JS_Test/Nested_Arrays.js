let arr = [[[1,2],3],[4,5],6];
// console.log(arr[2].length);

let ans = [];

function linearize(x){
    for(let i = 0; i < x.length; i++)
    {
        if(typeof(x[i]) == "object") linearize(x[i]);
        else ans.push(x[i]);
    }
}

linearize(arr);
console.log(ans);