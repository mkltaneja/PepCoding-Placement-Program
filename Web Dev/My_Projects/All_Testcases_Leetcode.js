const pup = require("puppeteer");

const email = "nevaki8762@whyflkj.com";
const pass = "hahahoho12";

async function main()
{
    let browser = await pup.launch({
        headless : false,
        defaultViewport : false,
        args : ["--start-maximized"]
    });
    let pages = await browser.pages();
    let tab = pages[0];
    await tab.goto("https://leetcode.com/accounts/login");
    await tab.type("#id_login", email);
    await tab.type("#id_password", pass);
    // await tab.keyboard.press("Enter");
    // await tab.waitForSelector(".btn__2_DK.fancy-btn__1eV0.primary__1l3Z.light__3h9J.btn__2ZIK.btn-md__1Zv4", {visible: true});
    // await tab.click(".btn__2_DK.fancy-btn__1eV0.primary__1l3Z.light__3h9J.btn__2ZIK.btn-md__1Zv4");
    console.log(tab);
}

main();