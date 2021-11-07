let s = process.argv[2];
let obj = {};
let cnt = [];
for(let i = 0; i < 26; i++)
    cnt[i] = 0;
for(let i in s)
        // console.log("File Not Found!");
    cnt[s.charCodeAt(i) - 97]++;

for(let i = 0; i < 26; i++)
    obj[String.fromCharCode(i+97)] = cnt[i];

console.log(obj);