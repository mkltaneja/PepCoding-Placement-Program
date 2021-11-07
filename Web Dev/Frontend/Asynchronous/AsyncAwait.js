const fs = require("fs");
// require("chromedriver");

// // const { resolve } = require("node:path");
// let wd = require("selenium-webdriver");
// let browser = new wd.builder().forBrowser('chrome').build();

// let abc = new promise(function(){
//     console.log(1);
//     browser.get("https://youtube.com");
//     console.log(2);
//     resolve(3);
// });

// abc.then(function(){
//     console.log(abc);
// });

async function readFile(){
    try{
        let data = await fs.promises.readFile("AsyncAwit.js", "utf-8");
        console.log(data);
    }
    catch(err){
        console.log("File Not Found!");
        // console.log(err);
    }
}

readFile();