let arr = [1,2,3,4,5,6,7,8,9]

// Copy of arr, where narr is pointing to arr
let narr = arr;

// Copy of narr using spread, where narr points to new location
let narr = [...arr];

// Will not effect copy using spread
arr[0] = 10;

console.log(arr);
console.log(narr);
