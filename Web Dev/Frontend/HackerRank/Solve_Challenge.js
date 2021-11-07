const pup = require("puppeteer");

const email = "nevaki8762@whyflkj.com";
const pass = "hahahoho";

let browserPromise = pup.launch({
    headless: false,
    defaultViewport: false
});

let tab;
browserPromise.then(function(browser){
    let pagesPromise = browser.pages();
    // console.log(pagesPromise);
    return pagesPromise;
}).then(function(pages){
    // console.log(pages.length);
    tab = pages[0];
    let pageOpenPromise = tab.goto("https://www.hackerrank.com/auth/login");
    return pageOpenPromise;
}).then(function(){
    let idPromise = tab.type("#input-1", email);
    return idPromise;
}).then(function(){
    let passPromise = tab.type("#input-2", pass);
    return passPromise;
}).then(function(){
    let loginPromise = tab.click(".ui-btn.ui-btn-large.ui-btn-primary.auth-button.ui-btn-styled");
    return loginPromise;
}).then(function(){
    let IpkwaitPromise = tab.waitForSelector("#base-card-1-link", {visible: true});
    return IpkwaitPromise;
}).then(function(){
    console.log("IPK Clicking");
    let IpkClickPromise = tab.click("#base-card-1-link");
    return IpkClickPromise;
}).then(function(){
    console.log("WMP Waiting");
    // let warmupWaitPromise = tab.waitForSelector(".ui-card.ui-layer-3.active-card", {visible: true});
    // OR=============================
    let warmupWaitPromise = tab.waitForSelector("a[data-attr1='warmup']", {visible: true});
    return warmupWaitPromise;
}).then(function(){
    console.log("WMP Clicking");
    // let warmupClickPromise = tab.click(".ui-card.ui-layer-3.active-card");
    // OR=============================
    let warmupClickPromise = tab.click("a[data-attr1='warmup']");
    return warmupClickPromise;
}).then(function(){
    console.log("allURLS Waiting");
    let allUrlsWaitPromise = tab.waitForSelector(".js-track-click.challenge-list-item", {visible: true});
    return allUrlsWaitPromise;
}).then(function(){
    console.log("allURLS Getting");
    let allUrlsPromise = tab.$$(".js-track-click.challenge-list-item");  // "$$" is like getElements in Selenium - it gives all elements with the mentioned class (for getElement - "$" is used)
    console.log(allUrlsPromise.length);
    // console.log(allUrlsPromise);
    return allUrlsPromise;
}).then(function(data){
    // console.log(data);
    let fetchUrlsPromises = [];
    for(let i of data)
    {
        let UrlPromise = tab.evaluate(function(ele){
            return ele.getAttribute("href");
        }, i);
        fetchUrlsPromises.push(UrlPromise);
    }
    return Promise.all(fetchUrlsPromises);
}).then(function(data){
    // console.log(data);
    let problemSovedPromise = SolveQuestion("https://www.hackerrank.com"+data[0]);
    for(let i in data)
    {
        problemSovedPromise = problemSovedPromise.then(function(){
            return SolveQuestion("https://www.hackerrank.com"+data[i]);
        });
    }
}).catch(function(err){
    // console.log("An Error Occured");
    console.log("Galti hui hai Bhai kuch");
    // console.log(err);
});

function SolveQuestion(Url){
    let problemUrl = Url;
    let editorialUrl = Url.replace("?", "/editorial?");
    return new Promise(function(resolve, reject){
        tab.goto(editorialUrl)
        .then(function(){
            
        })
        .then(function(){
            return tab.waitForSelector(".hackdown-content h3", {visible: true});
        }).then(function(){
            return languages = tab.$$(".hackdown-content h3");
        }).then(function(data){
            console.log(data);
            // let code
            // for(let i in languages)
            // {
            //     if(languages[i] == "C++")

            // }
        }).then(function(){
            resolve();
        }).catch(function(err){
            console.log("Something Went Wrong!");
        });



        //////////// INCOMPLETE*******************


    });
}


//////////////////////INCOMPLETE***************



