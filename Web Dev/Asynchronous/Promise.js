const fs = require("fs");

// let cond = true;

// let isitdone = new Promise(function(resolve, reject){
//     if(cond)
//         resolve("DONE!");
//     else 
//         reject("NOT DONE!");
// });

// console.log(isitdone);

// isitdone.then(function(val){
//     console.log(val);
// }).catch(function(err){
//     console.log(err);
// });


// let cond = false;

// let isitdone = new Promise(function(resolve, reject){
//     if(cond)
//         resolve("DONE!");
//     else 
//         reject("NOT DONE!");
// });

// console.log(isitdone);

// isitdone.then(function(val){
//     console.log(val);
// }).catch(function(err){
//     console.log(err);
// });

// // PROMISE.ALL()===============================================

// require("chromedriver");

// let wd = require("selenium-webdriver");
// let browser = new wd.builder().forBrowser('chrome').build();

// function myDisplayer(some) {
//     console.log(some);
//   }

// let myPromise = new Promise(function(myReject, myResolve) {
//     let x = 1;
  
//   // some code (try to change x to 5)
  
//     if (x == 0) {
//       myReject("OK");
//     } else {
//       myResolve("Error");
//     }
//   });
  
//   myPromise.then(
//     function(value) {myDisplayer(value);},
//     function(error) {myDisplayer("hello"+error);}
//   );

let readPromise = fs.promises.readFile("AsyncAwait.js", "utf-8");
// console.log(readPromise);
readPromise.then((data)=>{
    console.log(data);
}).catch((err)=>{
    console.log("File Not Found!");
});