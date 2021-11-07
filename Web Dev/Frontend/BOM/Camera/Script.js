
// Select the video element from the document
let body = document.querySelector("body");
let video = document.querySelector("video");

let vidbtn = document.querySelector("button#record");
let capbtn = document.querySelector("button#capture");

let filters = document.querySelectorAll(".filters");

let zoomIn = document.querySelector(".zoom-in");
let zoomOut = document.querySelector(".zoom-out");

// Give the required constraints, whether u want to turn ON the video or audio or both and more
let constraints = {video: true};
let mediaRecorder;
let isRecording = false;
let chunks = [];

let minZoom = 1;
let maxZoom = 4;
let currZoom = 1;

let filter = "";
vidbtn.addEventListener("click", function () {
    if (isRecording) 
    {
        mediaRecorder.stop();
        isRecording = false;
        let innerdiv = document.querySelector("#record div");
        innerdiv.classList.remove("animate-record");
    }
    else 
    {
        mediaRecorder.start();
        isRecording = true;
        let innerdiv = document.querySelector("#record div");
        innerdiv.classList.add("animate-record");
    }
});

// On Clicking capture button
capbtn.addEventListener("click", function () {
    let innerdiv = document.querySelector("#capture div");
    innerdiv.classList.add("animate-capture");
    setTimeout(function(){
        innerdiv.classList.remove("animate-capture");
    },500);
    capture();
});

// The feature of turning ON the camera is provided by the Browser, so we use the Navigator object
// Navigator is a browser object, which provides various functionalities, one of which is camera and audio access
// mediaDevices is an interface of navigator, which provide access to the connected media, like camera, mic, screen sharing etc.
// getUserMedia takes the media input, like which media to access; and returns a promise as mediaStream
navigator.mediaDevices
.getUserMedia(constraints)
.then(function (mediaStream) {
    
    video.srcObject = mediaStream;
    
    // options is just a fix of chrome for not showing the video after downloading
    let options = { mimeType: "video/webm; codecs=vp9" };
    
    // MediaRecorder() is an API that records the media provided by mediaStream
    mediaRecorder = new MediaRecorder(mediaStream, options);
    
    // mediaRecorder gets the data part by part, and it is acheived by dataavailable eventListener and we store it in chunks array
    mediaRecorder.addEventListener("dataavailable", function (e) {
        chunks.push(e.data);
    });
    mediaRecorder.addEventListener("stop", function () {
        
        // Blob is an inbuilt function, that collects the chunks and make the required data of "video.mp4" type
        let blob = new Blob(chunks, { type: "video/mp4" });

        addMedia("vid", blob);
        
        // chunks are used so make it empty
        chunks = [];
        
        // It is a property of browser which creates the URL of the object
        let url = URL.createObjectURL(blob);
        
        // For Downloading the video
        let a = document.createElement("a");
        a.href = url;
        a.download = "video.mp4";
        a.click();
        a.remove();
    });
});

for(let i = 0; i < filters.length; i++)
{
    filters[i].addEventListener("click", function(e){
        console.log(filters[i]);
        filter = e.currentTarget.style.backgroundColor;
        // console.log(filter);
        removeFilter();
        applyFilter(filter);
    });
}

function capture()
{
    let c = document.createElement("canvas");

    // The difference between width/height and videoWidth/videoHeight is that width/height is the property of <video> tag of HTML, which is 0 by default
    // BUT videoWidth/videoHeight is the property of the ongoing video inside that tag, which has the resolution of the device by default
    // And we want our canvas to have same height/width as of video
    c.height = video.videoHeight;
    c.width = video.videoWidth;

    let ctx = c.getContext("2d");

    // translate property of canvas takes (x,y) coordinate as arguments, which translate x units in x axis, and y units in y axis
    // ctx.translate(c.height/2, c.width/2);

    ctx.translate(c.width/2, c.height/2);
    ctx.scale(currZoom, currZoom);
    ctx.translate(-c.width/2, -c.height/2);
    // Draws image whatever is in video at (0,0)
    ctx.drawImage(video, 0, 0);
    if(filter != "")
    {
        ctx.fillStyle = filter;
        ctx.fillRect(0, 0, c.width, c.height);
    }

    let a = document.createElement("a");
    a.download = "image.jpg";
    a.href = c.toDataURL();
    addMedia("img", c.toDataURL());
    a.click();
    a.remove();
}

zoomIn.addEventListener("click",function(e){
    if(currZoom < maxZoom)
    {
        currZoom += 0.5;
        video.style.transform = `scale(${currZoom})`;
    }
});

zoomOut.addEventListener("click",function(e){
    if(currZoom > minZoom)
    {
        currZoom -= 0.1;
        video.style.transform = `scale(${currZoom})`;
    }
});


function applyFilter(filterColor)
{
    let filterdiv = document.createElement("div");
    filterdiv.classList.add("filter-div");
    console.log(filterColor);
    filterdiv.style.backgroundColor = filterColor;
    body.appendChild(filterdiv);
}

function removeFilter()
{
    let filterdiv = document.querySelector(".filter-div");
    if(filterdiv)
        filterdiv.remove();
}