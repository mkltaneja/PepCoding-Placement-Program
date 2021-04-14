require("chromedriver");
const fs = require("fs");

let wd = require("selenium-webdriver");
let chrome = require("selenium-webdriver/chrome");
// let browser = new wd.Builder().forBrowser('chrome').build();
let browser = new wd.Builder().forBrowser('chrome').setChromeOptions(new chrome.Options().headless()).build();
let matchId = 30880;

let batsmanColumns = ["matches", "innings", "notOut", "runs", "highestScore", "average", "BallsPlayed", "strikeRate", "hundreds", "twoHundreds", "fifties", "fours", "sixes"];
let bowlerColumns = ["matches", "innings", "balls", "runs", "wickets", "bestBowlingInInnings", "bestBowlingInMatch", "economy", "bowlingAverage", "bowlingStrikeRate", "fiveWicketsInning", "tenWicketsMatch"];

let inningsiBatsmen = [];
let inningsiBowlers = [];
let careerData = [];
let innings = 1;

let playersAdded = 0;


async function getCareerData(url, i, totalPlayers)
{
    // let browser = new wd.Builder().forBrowser('chrome').setChromeOptions(new chrome.Options().addArguments("--headless")).build();
    let browser = new wd.Builder().forBrowser('chrome').setChromeOptions(new chrome.Options().headless()).build();
    // let browser = new wd.Builder().forBrowser('chrome').build();
    await browser.get(url);
    await browser.wait(wd.until.elementLocated(wd.By.css("table")));
    let tables = await browser.findElements(wd.By.css("table"));
    // console.log(tables.length);
    for(let j in tables)
    {
        let data = {};
        let rows = await tables[j].findElements(wd.By.css("tbody tr"));
        // console.log(tables.length);
        for(let row of rows)
        {
            let tempData = {};
            let columns = await row.findElements(wd.By.css("td"));
            let matchType = await columns[0].getAttribute("innerText");
            let keyArr;
            if(j == 0)
                keyArr = batsmanColumns;
            else if(j == 1)
                keyArr = bowlerColumns;
            for(let k = 1; k < columns.length; k++)
                tempData[keyArr[k-1]] = await columns[k].getAttribute("innerText");
            data[matchType] = tempData;
        }

        if(j == 0)
            careerData[i]["BattingCareer"] = data;
        else if(j == 1)
            careerData[i]["BowlingCareer"] = data;
    }
    await browser.close();
    playersAdded++;
    if(playersAdded == totalPlayers)
        fs.writeFileSync("Career.json", JSON.stringify(careerData));
}


async function main()
{
    await browser.get(`https://www.cricbuzz.com/live-cricket-scores/${matchId}`);
    await browser.wait(wd.until.elementLocated(wd.By.css(".cb-nav-bar a")));
    let buttons = await browser.findElements(wd.By.css(".cb-nav-bar a"));
    await buttons[1].click();
    await browser.wait(wd.until.elementLocated(wd.By.css(`#innings_${innings} .cb-col.cb-col-100.cb-ltst-wgt-hdr`)));
    let tables = await browser.findElements(wd.By.css(`#innings_${innings} .cb-col.cb-col-100.cb-ltst-wgt-hdr`));
    // console.log(tables.length);
    let inningsiBatsmenRows = await tables[0].findElements(wd.By.css(".cb-col.cb-col-100.cb-scrd-itms"));
    // console.log(inningsiBatsmenRows.length);
    for(let i = 0; i < (inningsiBatsmenRows.length - 3); i++)
    {
        let columns = await inningsiBatsmenRows[i].findElements(wd.By.css("div"));
        if(columns.length == 7)
        {
            let url = await columns[0].findElement(wd.By.css("a")).getAttribute("href");
            let playerName = await columns[0].getAttribute('innerText');
            careerData.push({"playername" : playerName});
            inningsiBatsmen.push(url);
        }
    }
    // console.log(inningsiBatsmen);

    let inningsiBowlerRows = await tables[1].findElements(wd.By.css(".cb-col.cb-col-100.cb-scrd-itms"));
    for(let i = 0; i < inningsiBowlerRows.length; i++)
    {
        let columns = await inningsiBowlerRows[i].findElements(wd.By.css("div"));
        // console.log(columns.length);
        if(columns.length == 8)
        {
            let url = await columns[0].findElement(wd.By.css("a")).getAttribute("href");
            let playerName = await columns[0].getAttribute("innerText");
            careerData.push({"playerName" : playerName});
            inningsiBowlers.push(url);
        }
    }
    // console.log(inningsiBowlers);

    let finalUrls = inningsiBatsmen.concat(inningsiBowlers);
    // console.log(finalUrls);
    for(let i in finalUrls)
    {
        getCareerData(finalUrls[i], i, finalUrls.length);
    }
}

main();

