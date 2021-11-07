require("chromedriver");
let wd = require("selenium-webdriver");

let browser = new wd.Builder().forBrowser('chrome').build();


async function fun()
{
    await browser.get("https://github.com/topics");
    await browser.wait(wd.until.elementLocated(wd.By.css(".container-lg.p-responsive.mt-6 ul li a")));
    let table = await browser.findElements(wd.By.css(".container-lg.p-responsive.mt-6 ul li a"));
    // console.log(table.length);
    // console.log(table);
    let topics = [];
    for(let i in table)
    {
        // let browser = new wd.Builder().forBrowser('chrome').build();
        // browser.get(table[i].getAttribute("href"));
        await browser.wait(wd.until.elementLocated(wd.By.css("f3.lh-condensed.text-center.Link--primary.mb-0.mt-1")));
        let topic = await table[i].findElement(wd.By.css("f3.lh-condensed.text-center.Link--primary.mb-0.mt-1")).getAttribute("innerText");
        console.log(topic);
        // await browser.wait(wd.until.elementLocated(wd.By.css(".col-md-8.col-lg-9 article")));
        // let projects = await browser.findElements(wd.By.css(".col-md-8.col-lg-9 article"));
        // console.log(articles.length);

        
        // for(let j in articles)
        // {
        //     if(j == 8)
        //         break;
        //     await browser.wait(wd.until.elementLocated(wd.By.css(".tabnav.px-3.mb-0 nav a")));
        //     let buttons = await browser.findElements(wd.By.css(".tabnav.px-3.mb-0 nav a"));
        //     // console.log(buttons.length);
        //     await browser.get(buttons[1].getAttribute("href"));
        //     // await button[1].click();
        // }
    }

}

fun();