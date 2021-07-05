// Database -> create / open (camera)
// Database ObjectStore => Gallery
// Photo capture / video capture => gallery(obs) store

// Format:
// data = {
//     mId: 13120140808,
//     type: "img"/"vid",
//     media: mera actual content {img => c.toDataUrl / vid => blob,
// }

let dbAccess;
let request = indexedDB.open("Camera", 1); // (Database, version)
// We are taking version as 1, as we do not need to increase our version or this project

request.addEventListener("success", function(){
    // alert("New DB created");
    dbAccess = request.result;
    viewMedia();
});

request.addEventListener("upgradeneeded", function(){
    // alert("Version Updated");
    let db = request.result;
    db.createObjectStore("gallery", {keyPath: "mId"});
});

request.addEventListener("error", function(){
    alert("Some error Occured");
});

function addMedia(type, media)
{
    // Assumption here - I have dbAccess (i.e. dbAccess != undefined)
    let tx = dbAccess.transaction("gallery", "readwrite");
    let galleryObjectStore = tx.objectStore("gallery");
    let data = {
        mId: Date.now(),
        type,
        media
    };
    galleryObjectStore.add(data);
}

function viewMedia()
{
    // Assumption here - I have dbAccess (i.e. dbAccess != undefined)
    let tx = dbAccess.transaction("gallery", "readonly");
    let galleryObjectStore = tx.objectStore("gallery");
    let req = galleryObjectStore.openCursor();
    req.addEventListener("success", function(){
        let cursor = req.result;
        if(cursor)
        {
            // console.log(cursor);
            let mediaCard = document.createElement("div");
            mediaCard.classList.add("media-card");
            mediaCard.innerHTML = `<div class="media-container">${cursor.value.type}</div>`;
            console.log(mediaCard);
            cursor.continue();
        }
    });
}