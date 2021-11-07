// npm init -y
// npm i express


const express = require("express");

// initialize server
const app = express();

// function -> route, path
// Frontend -> req -> "/"
app.get("/", function(req, res){ // (request, response)
    console.log("Hello from Home Page");
    res.send("<h1> Hello from Backend </h1>");
})

let obj = {
    name: "Mukul"
}

app.get("/user", function(req, res){
    console.log("Users");

    // for sending key value pair
    res.json(obj);
})

// localhost:8080
app.listen(8080, function(){
    console.log("server started");
})