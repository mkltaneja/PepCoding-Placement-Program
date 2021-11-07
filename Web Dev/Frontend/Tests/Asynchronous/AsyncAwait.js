const fs = require("fs");

async function Solution(){
    let sum = 0;

    let n = 2;
    for(let i = 1; i <= n; i++)
    {
        let arr = new Array(101);
        
        for(let i = 0; i < 50; i++)
        {
            let idx = Math.floor(Math.random()*101);
            // console.log(idx);
            arr[idx] = idx;
        }
        
        for(let i = 0; i < arr.length; i++)
        {
            if(arr[i] == undefined)
                arr[i] = "\n\r";
        }
        // for(let i = 0; i < arr.length; i++)
        // {
        //     console.log(arr[i]);
        // }
        fs.promises.writeFile(`${i}.txt`, arr);
        let pfile = await fs.promises.readFile(`${i}.txt`, "utf-8");
        console.log(pfile);
        // pfile.then(function(data){
        //     console.log(data);
        // }).catch(function(err){
        //     console.log("File Not Found!");
        // });

        for(let i = 0; i < pfile.length; i++)
            if(pfile[i] != "\r\n")
                sum += pfile[i];
    }

    console.log(sum);
}

Solution();