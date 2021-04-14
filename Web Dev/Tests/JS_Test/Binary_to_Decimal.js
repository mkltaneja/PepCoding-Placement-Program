
function dectobin(s)
{
    let n = 0;
    var ans = "", i = 0;
    while(i < s.length)
        n = n*10 + (s[i++]-'0');
    // console.log(n);
    while(n)
    {
        ans += (n%2);
        // console.log(n);
        n = parseInt(n/2);
    }
    // console.log(ans);
    // ans.split("").reverse().join("");
    // console.log(ans);
    return ans.split("").reverse().join("");
}

function main()
{
    let s = "11";
    console.log(dectobin(s));
}

main();