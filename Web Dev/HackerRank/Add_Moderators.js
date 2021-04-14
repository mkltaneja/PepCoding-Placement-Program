const pup = require("puppeteer");

const email = "nevaki8762@whyflkj.com";
const pass = "hahahoho";

const moderators = ["Mukul", "mkltaneja", "12arpit", "Shubham786", "abcd", "Keshav", "Haha", "Hoho", "wxyz", "Shubh", "skfhs", "jasifh", "jsfiafh", "asdh", "jclasihfals", "asf", "asfs", "acha", "hmmmmmm", "aisekaise", "sdkljkhgs", "dfuguibsh", "dggdfg", "dogy", "billy", "mouse", "sher", "heavydriver", "bete", "beeeteeeeeeeeee"]

async function main(){
    let browser = await pup.launch({
        headless: false,
        defaultViewport: false,
        args: ["--start-maximized"]
    });
    let pages = await browser.pages();
    let tab = pages[0];
    
    await tab.goto("https://www.hackerrank.com/auth/login");
    await tab.type("#input-1", email);
    await tab.type("#input-2", pass);
    await tab.click(".ui-btn.ui-btn-large.ui-btn-primary.auth-button.ui-btn-styled");
    await tab.waitForNavigation({waitUntil : "networkidle2"});
    await tab.click(".dropdown-handle.nav_link.toggle-wrap");
    await tab.click("a[data-analytics='NavBarProfileDropDownAdministration']");
    await tab.waitForSelector(".nav-tabs.nav.admin-tabbed-nav li", {visible: true});
    let list = await tab.$$(".nav-tabs.nav.admin-tabbed-nav li");
    await list[1].click();
    // await tab.waitForNavigation({waitUntil : "networkidle2"});
    await tab.waitForSelector(".btn.btn-green.backbone.pull-right", {visible: true});
    let CreateChallengeButton = await tab.$(".btn.btn-green.backbone.pull-right");

    await tab.waitForSelector(".backbone.block-center", {visible: true});
    let challenges = await tab.$$(".backbone.block-center");
    let challengesUrl = [];
    for(let i in challenges)
    {
        let url = await tab.evaluate(function(ele){
            return ele.getAttribute("href");
        },challenges[i]);
        challengesUrl.push(url);
    }

    for(let i in challengesUrl)
    {
        console.log(challengesUrl[i]);
        await add_moderator("https://www.hackerrank.com"+challengesUrl[i]+"/moderators", await browser.newPage());
    }
}

async function add_moderator(url, tab){
    await tab.goto(url);
    // console.log(url);
    await tab.waitForSelector("#moderator");
    let n = Math.floor(Math.random()*1000) % (moderators.length);
    // console.log(n);
    for(let i = 0; i < n; i++)
    {
        let idx = Math.floor(Math.random()*1000) % (moderators.length);
        // console.log(idx + " --> ");
        await tab.waitForSelector("#moderator", {visible: true});
        await tab.type("#moderator", moderators[idx]);
        // console.log(moderators[idx]);
        await tab.keyboard.press("Enter");
    }
}

main();