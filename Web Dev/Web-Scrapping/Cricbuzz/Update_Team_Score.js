require("chromedriver");

let wd = require("selenium-webdriver");
let browser = new wd.Builder().forBrowser('chrome').build();

async function main()
{
    await browser.get("https://www.cricbuzz.com/cricket-series/3130/indian-premier-league-2020/matches");
    
}

main();