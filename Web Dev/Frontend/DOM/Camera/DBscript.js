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

request.addEventListener("success", function () {
    // alert("New DB created");
    dbAccess = request.result;
    viewMedia();
});

// Note:- upgradeneeded event is fired before the success event
request.addEventListener("upgradeneeded", function () {
    // alert("Version Updated");
    let db = request.result;
    db.createObjectStore("gallery", { keyPath: "mId" });
});

request.addEventListener("error", function () {
    alert("Some error Occured");
});

function addMedia(type, media) {
    console.log(type);
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

function viewMedia() {
    // Assumption here - I have dbAccess (i.e. dbAccess != undefined)
    let tx = dbAccess.transaction("gallery", "readonly");

    let galleryObjectStore = tx.objectStore("gallery");

    let req = galleryObjectStore.openCursor();

    req.addEventListener("success", function () {
        let cursor = req.result;
        if (cursor) {
            // console.log(document);
            console.log(cursor.value);
            let mediaCard = document.createElement("div");
            let container = document.querySelector(".container");
            mediaCard.classList.add("media-card");
            mediaCard.innerHTML = `<div class="media-container">${cursor.value.type}</div>
                                    <div class="action-container">
                                        <button class="media-download">DOWNLOAD</button>
                                        <button class="media-delete" data-id=${cursor.value.mId}>DELETE</button>
                                    </div>`;
            let mediaContainer = mediaCard.querySelector(".media-container");
            console.log(container);
            console.log(mediaCard);

            let downloadBtn = mediaCard.querySelector(".media-download");
            let deleteBtn = mediaCard.querySelector(".media-delete");

            deleteBtn.addEventListener("click", function (e) {

                // Deleting media card from HTML
                e.currentTarget.parentElement.parentElement.remove();

                // Deleting media card from Database
                let mId = e.currentTarget.getAttribute("data-id");
                deleteMediaFromDB(mId);
            });

            if (cursor.value.type == "img") {
                let img = document.createElement("img");
                img.classList.add("media-gallery");
                img.src = cursor.value.media;
                mediaContainer.appendChild(img);

                downloadBtn.addEventListener("click", function (e) {
                    let a = document.createElement("a");
                    a.download = "My Image.jpeg";

                    a.href = e.currentTarget.parentElement.parentElement.querySelector(".media-gallery").src;
                    // OR //
                    // a.href = img.src;

                    a.click();
                    a.remove();
                });
            }
            else if (cursor.value.type == "vid") {
                let vid = document.createElement("video");
                vid.classList.add("media-gallery");
                vid.src = URL.createObjectURL(cursor.value.media);
                vid.addEventListener("mouseenter", function () {
                    vid.currentTime = 0;
                    vid.play();
                });
                vid.addEventListener("mouseleave", function () {
                    vid.pause();
                    vid.currentTime = 0;
                });
                // vid.autoplay = true;
                vid.controls = true;
                vid.loop = true;
                vid.muted = true;
                mediaContainer.appendChild(vid);

                downloadBtn.addEventListener("click", function () {
                    let a = document.createElement("a");
                    a.download = "My Video.mp4"
                    a.href = vid.src;
                    a.click();
                    a.remove();
                });
            }
            container.append(mediaCard);

            cursor.continue();
        }
    });
}

function deleteMediaFromDB(mId) {
    let tx = dbAccess.transaction("gallery", "readwrite");
    let galleryObjectStore = tx.objectStore("gallery");
    console.log(typeof (mId));
    galleryObjectStore.delete(Number(mId));
}