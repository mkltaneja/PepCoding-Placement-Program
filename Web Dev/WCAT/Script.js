#!/usr/bin/env node

// const fs = require('fs')

// fs.writeFileSync("abc.txt", "Hello This is Mukul");

// let data = fs.readFileSync("abc.txt", "utf-8");

// fs.writeFileSync("abc.txt",data + "Hello this is Mukul Taneja");

// console.log(fs.existsSync("ab.txt"));
// console.log(data);
// console.log(fs);

let cmds = process.argv;
const fs = require("fs");
// console.log(fs.readFileSync("abc.txt", "utf-8"));
fs.readFileSync("abc.txt");

function wcat(cmds){
    // If I need files, starting with "-"
    let options = cmds.filter(function(data, index){
        return data.startsWith("-");
    });
    let files = cmds.filter(function(data,index){
        return !data.startsWith("-");
    });


    //Error handling
    if(files.length == 0){
        // console.log("Please specify a file name to read");
        console.log("File ka naam to daal le Chutiye");
        return;
    }

    
    for(i in files){
        if(!fs.existsSync(files[i])){
            // console.log(files[i] + "The input file does not exist");
            console.log(files[i] + " wali file hi ni ha g**nd maraa");
            return;
        }
    }

    let numbering = 1;

    // Reading and printing the input files
    for(i in files){
        let data = fs.readFileSync(files[i], "utf-8");
        // fs.writeFileSync(files[i], data +" OYEE HOYEE");

        if(options.includes("-s")){
            let lines = data.split("\r\n");
            for(j in lines){
                // if(lines[j] != ""){
                    if(options.includes("-n") || options.includes("-b"))
                        console.log(numbering++ + ".) " + lines[j]);
                // }
            }
        }

        else if(options.includes("-n"))
        {
            let lines = data.split("\r\n");
            for(j in lines)
            {
                if(lines != "")
                {
                    console.log(lines);
                }
            }
        }

        // console.log(data);
    }


    // Writing commands (Writing content of 1st file into 2nd)
    if(options.includes("-w"))
    {
        if(options.length != 1 || files.length != 2 || cmds.indexOf("-w") != 1)
            console.log("Command not Found!");
        let data = fs.readFileSync(files[0], "utf-8");
        fs.writeFileSync(files[1], data);
        // console.log(files);
        return;
    }
    else if(options.includes("-a"))
    {
        if(options.length != 1 || files.length != 2 || cmds.indexOf("-a") != 1)
        {
            console.log("Command Not Found!");
            return;
        }
        let file1 = fs.readFileSync(files[0], "utf-8");
        let file2 = fs.readFileSync(files[1], "utf-8");
        fs.writeFileSync(files[1], file2 + "\n" + file1);
        return;
    }

    // overwriting 2nd file with 1st file with no empty lines
    else if(options.includes("-ws"))
    {
        if(options.length != 1 || files.length != 2 || cmds.indexOf("-ws") != 1)
        {
            console.log("Command Not Found");
            return;
        }
        let data = fs.readFileSync(files[0], "utf-8");
        let lines = data.split("\r\n");
        files[1] = fs.writeFileSync(files[1], "");
        for(i in lines)
        {
            if(lines[i] != "")
                files[1] = fs.writeFileSync(files[1], files[1]+lines[i]);
        }
    }

}
// wcat(cmds);
// console.log(files);