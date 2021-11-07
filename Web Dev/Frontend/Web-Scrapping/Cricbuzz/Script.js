require("chromedriver");

let wd = require("selenium-webdriver");
let browser = new wd.Builder().forBrowser('chrome').build();
let matchId = 30880;

let batsmanColumns = ["PlayerName", "out", "runs", "ballsPlayed", "fours", "sixes", "strikeRate"];
let bowlerColumns = ["playerName", "overs", "maidenOvers", "runs", "wickets", "noBalls", "wideBalls", "economy"];

let inningsiBatsmen = [];
let inningsiBowlers = [];
let innings = 1;

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
        let data = {};
        for(let j in columns)
        {
            if(j != 1)
            {
                data[batsmanColumns[j]] = await columns[j].getAttribute("innerText");
            }
        }
        inningsiBatsmen.push(data);
    }
    console.log(inningsiBatsmen);

    let inningsiBowlerRows = await tables[1].findElements(wd.By.css(".cb-col.cb-col-100.cb-scrd-itms"));
    // console.log(inningsiBowlerRows.length);
    for(let i = 0; i < inningsiBowlerRows.length; i++)
    {
        // console.log(inningsiBowlerRows.length);
        await browser.wait(wd.until.elementLocated(wd.By.css("div")));
        let columns = await inningsiBowlerRows[i].findElements(wd.By.css("div"));
        // console.log(columns.length);
        if(columns.length == 8)
        {
            let data  = {};
            for(let j in columns)
            {
                data[bowlerColumns[j]] = await columns[j].getAttribute("innerText");
            }
            inningsiBowlers.push(data);
        }
    }
    console.log(inningsiBowlers);

    await browser.close();
}

main();
