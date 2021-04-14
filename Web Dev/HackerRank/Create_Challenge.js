const pup = require("puppeteer");

const email = "nevaki8762@whyflkj.com";
const pass = "hahahoho";
const challenges = require("./All_Challenges");

let tab;
async function main(){
    let browser = await pup.launch({
        headless: false,
        defaultViewport: false,
        args: ["--start-maximized"]
    });
    let pages = await browser.pages();
    tab = pages[0];
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

    let CreateChallengeUrl = await tab.evaluate(function(ele){
        return ele.getAttribute("href");
    }, CreateChallengeButton);

    for(let i = 5; i < 7; i++)
        await CreateChallenge("https://www.hackerrank.com"+CreateChallengeUrl, challenges[i], await browser.newPage());
}

async function CreateChallenge(url, challenge, tab){
    await tab.goto(url);
    await tab.waitForSelector("#name", {visible: true});
    await tab.type("#name", challenge["Challenge Name"]);
    await tab.waitForSelector("#preview", {visible: true});
    await tab.type("#preview", challenge["Description"]);
    await tab.waitForSelector("#problem_statement-container .CodeMirror.cm-s-default.CodeMirror-wrap textarea", {visible: true});
    await tab.type("#problem_statement-container .CodeMirror.cm-s-default.CodeMirror-wrap textarea", challenge["Problem Statement"]);
    await tab.type("#input_format-container .CodeMirror.cm-s-default.CodeMirror-wrap textarea", challenge["Input Format"]);
    await tab.type("#constraints-container .CodeMirror.cm-s-default.CodeMirror-wrap textarea", challenge["Constraints"]);
    await tab.type("#output_format-container .CodeMirror.cm-s-default.CodeMirror-wrap textarea", challenge["Output Format"]);
    await tab.waitForSelector("#tags_tag", {visible: true});
    await tab.type("#tags_tag", challenge["Tags"]);
    await tab.keyboard.press("Enter");
    await tab.click(".save-challenge.btn.btn-green");
}

main();