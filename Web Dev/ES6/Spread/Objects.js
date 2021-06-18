

// VERY IMPORTANT NOTE:- All arrays, objects, functions variables are stored in the heap memory







let state = {
    name: "John",
    address: {
        city: "London",
        country: {
            countryName: "United Knigdom",
            countryCode: "UK"
        }
    }
}

// In Shallow copy for the object that is spread, the uppermost level is created at a new memory space
// The properties of the uppermost level remains the same
// The lower levels are not affected by this. They keep on pointing to their original references

// ========== Level 1 copy =========== //

// Shallow copy -> where only the address of the uppermost object is copied, and not the objects inside it
// let copy = {...state};

// Copy, pointing to the same location as of state
// let copy = state;

// copy["name"] = "Mukul"
// Address is another object in the state object, which points to the different location from state, so changing its value will reflect changes in the original also as it was not copied to different location
// copy.address.city = "Delhi";

// console.log(state);
// console.log(copy);


// ============ Level 2 Copy ============ //

// let doubleCopy = {
//     ...state,
//     address: {
//         ...state.address
//     }
// }

// doubleCopy.address.city ="Delhi"
// doubleCopy.address.country.countryCode = "In"

// console.log(state);
// console.log(doubleCopy);

// =========== Level 3 Copy ========== //

// let deepCopy = {
//     ...state,
//     address: {
//         ...state.address,
//         country: {
//             ...state.address.country
//         }
//     }
// }


// deepCopy.address.city ="Delhi"
// deepCopy.address.country.countryCode = "In"

// console.log(state);
// console.log(deepCopy);


// Final Method to do Deep Copy:- 

let deepCopy = JSON.parse(JSON.stringify(state));

deepCopy.address.city ="Delhi"
deepCopy.address.country.countryCode = "In"

console.log(state);
console.log(deepCopy);