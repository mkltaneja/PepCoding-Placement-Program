
function bintodec(s)
{
    let ans = 0, i = 0;
    while(i < s.length)
        ans = ans*2 + (s[i++]-'0');
    return ans;
}

function main()
{
    let s = "1001";
    console.log(bintodec(s));
}

main();