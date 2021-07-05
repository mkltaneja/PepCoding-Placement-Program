// Adding the Perfect Scrollbar
const ps = new PerfectScrollbar(`#cells`, {
    wheelSpeed: 1
});

// Naming rows and columns
for (let i = 1; i <= 100; i++) {
    let str = "";
    let n = i;

    while (n > 0) {
        let rem = n % 26;
        if (rem == 0) {
            str = "Z" + str;
            n = Math.floor(n / 26) - 1;
        }
        else {
            str = String.fromCharCode((rem - 1) + 65) + str;
            n = Math.floor(n / 26);
        }
    }
    $("#columns").append(`<div class="column-name">${str}</div>`);
    $("#rows").append(`<div class="row-name">${i}</div>`);
}

let cellData = {
    "Sheet 1": {}
};

let selectedSheet = "Sheet 1";
let totalSheets = 1;
let lastlyAddedSheet = 1;
let saved = true;

let defaultProperties = {
    "font-family": "Noto Sans",
    "font-size": 14,
    "text": "",
    "bold": false,
    "italic": false,
    "underlined": false,
    "alignment": "left",
    "color": "444",
    "bgcolor": "#fff"
};

// Constructing cells
for (let i = 1; i <= 100; i++) {
    let row = $(`<div class="cell-row"></div>`);
    for (let j = 1; j <= 100; j++)
        row.append(`<div id="row-${i}-col-${j}" class="input-cell" contenteditable="false"></div>`);
    $("#cells").append(row);
}

// For scrolling Rows and columns along with the cells
$("#cells").scroll(function (e) {
    $("#rows").scrollTop(this.scrollTop);
    $("#columns").scrollLeft(this.scrollLeft);
});

// Making cell editable by double clicking
$(".input-cell").dblclick(function (e) {
    $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    $(this).addClass("selected");
    $(this).attr("contenteditable", "true");
    $(this).focus();
});

// Getting row and columns of the selected cell
function getrowcol(ele) {
    let id = $(ele).attr("id");
    let idArray = id.split("-");
    let rowId = parseInt(idArray[1]);
    let colId = parseInt(idArray[3]);

    // console.log(ele);

    return [rowId, colId];
}

// Getting Top, Bottom, Right, Left of the selected cell
function getTopBottomLeftRight(rowId, colId) {
    // console.log(rowId);
    // console.log(colId);

    let topCell = $(`#row-${rowId - 1}-col-${colId}`);
    let bottomCell = $(`#row-${rowId + 1}-col-${colId}`);
    let leftCell = $(`#row-${rowId}-col-${colId - 1}`);
    let rightCell = $(`#row-${rowId}-col-${colId + 1}`);

    // console.log(topCell);
    // console.log(bottomCell);
    // console.log(leftCell);
    // console.log(rightCell);

    return [topCell, bottomCell, leftCell, rightCell];
}

// Operations after one is selected and making more than one cell selectable
function selectCell(ele, e, topCell, bottomCell, leftCell, rightCell) {
    if (e.ctrlKey) {
        let topSelected;
        if (topCell)
            topSelected = topCell.hasClass("selected");

        let bottomSelected;
        if (bottomCell)
            bottomSelected = bottomCell.hasClass("selected");

        let leftSelected;
        if (leftCell)
            leftSelected = leftCell.hasClass("selected");

        let rightSelected;
        if (rightCell)
            rightSelected = rightCell.hasClass("selected");

        if (topSelected) {
            $(ele).addClass("top-selected");
            (topCell).addClass("bottom-selected");
        }

        if (bottomSelected) {
            $(ele).addClass("bottom-selected");
            (bottomCell).addClass("top-selected");
        }

        if (leftSelected) {
            $(ele).addClass("left-selected");
            (leftCell).addClass("right-selected");
        }

        if (rightSelected) {
            $(ele).addClass("right-selected");
            (rightCell).addClass("left-selected");
        }
    }
    else
        $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    $(ele).addClass("selected");
    changeHeader(getrowcol(ele));
}

// For Unselecting the chosen cell - removing the "selected" classes
function unselectCell(ele, e, topCell, bottomCell, leftCell, rightCell) {
    if ($(ele).attr("contenteditable") == "false") {
        if ($(ele).hasClass("top-selected"))
            topCell.removeClass("bottom-selected");

        if ($(ele).hasClass("bottom-selected"))
            bottomCell.removeClass("top-selected");

        if ($(ele).hasClass("left-selected"))
            leftCell.removeClass("right-selected");

        if ($(ele).hasClass("right-selected"))
            rightCell.removeClass("left-selected");

        $(ele).removeClass("selected top-selected bottom-selected left-selected right-selected");
    }
}

// After single clicking a cell
$(".input-cell").click(function (e) {
    // $(this).attr("contenteditable", "false");
    let [rowId, colId] = getrowcol(this);
    let [topCell, bottomCell, leftCell, rightCell] = getTopBottomLeftRight(rowId, colId);

    if ($(this).hasClass("selected") && e.ctrlKey)
        unselectCell(this, e, topCell, bottomCell, leftCell, rightCell);
    else
        selectCell(this, e, topCell, bottomCell, leftCell, rightCell);
});

function updateStyle(style, data) {
    if (data[style])
        $(`#${style}`).addClass("selected");
    else
        $(`#${style}`).removeClass("selected");
}

function changeHeader([rowId, colId]) {
    let data;
    if (cellData[selectedSheet][rowId - 1] && cellData[selectedSheet][rowId - 1][colId - 1])
        data = cellData[selectedSheet][rowId - 1][colId - 1];
    else
        data = defaultProperties;

    $("#font-family").val(data["font-family"]);
    $("#font-size").val(data["font-size"]);
    updateStyle("bold", data);
    updateStyle("italic", data);
    updateStyle("underlined", data);
    $("#fill-color").css("border-bottom", `5px solid ${data["bgcolor"]}`);
    $("#text-color").css("border-bottom", `5px solid ${data["color"]}`);
    $(".alignment.selected").removeClass("selected");
    $(`.alignment[data-type=${data["alignment"]}]`).addClass("selected");
}

// If we a cell without ctrl Key the previous selected cell(s) become blur
$(".input-cell").blur(function (e) {
    $(this).attr("contenteditable", "false");
    updateCellData("text", $(this).text());
});

function selectAllbetween(startCell, endCell) {
    $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    for (let i = Math.min(startCell.rowId, endCell.rowId); i < Math.max(startCell.rowId, endCell.rowId); i++) {
        for (let j = Math.min(startCell.colId, endCell.colId); j < Math.max(startCell.colId, endCell.colId); j++) {
            let [top, bottom, left, right] = getTopBottomLeftRight(i, j);
            // console.log($(`#row-${i}-col-${j}`)[0]);
            selectCell($(`#row-${i}-col-${j}`)[0], { "ctrlKey": true }, top, bottom, left, right);
        }
    }
}

let startCellSelected = false;
let startCell = {};
let endCell = {};
$(".input-cell").mousemove(function (e) {
    e.preventDefault();
    if (e.buttons == 1) {
        if (!startCellSelected) {
            let [rowId, colId] = getrowcol(this);
            startCell = { "rowId": rowId, "colId": colId };
            startCellSelected = true;
            selectAllbetween(startCell, endCell);
            // console.log(startCell, endCell);
        }
    }
    else
        startCellSelected = false;
});

$(".input-cell").mouseenter(function (e) {
    if (e.buttons == 1) {
        if (e.pageX > 10 && scrollXLStarted) {
            clearInterval(scrollXLinterval);
            scrollXLStarted = false;
        }
        else if (e.pageX < ($(window).width() - 10) && scrollXRStarted) {
            clearInterval(scrollXRinterval);
            scrollXRStarted = false;
        }

        let [rowId, colId] = getrowcol(this);
        endCell = { "rowId": rowId, "colId": colId };
        selectAllbetween(startCell, endCell);
    }
});

let scrollXLStarted = false;
let scrollXRStarted = false;
let scrollXLinterval;
let scrollXRinterval;

function scrollXL() {
    scrollXLStarted = true;
    scrollXLinterval = setInterval(() => {
        $("#cells").scrollLeft($("#cells").scrollLeft() - 100)
    }, 100);
}

function scrollXR() {
    scrollXRStarted = true;
    scrollXRinterval = setInterval(() => {
        $("#cells").scrollLeft($("#cells").scrollLeft() - 100)
    }, 100);
}

$(".data-container").mousemove(function (e) {
    e.preventDefault();
    if (e.buttons == 1) {
        if (e.pageX < (10) && !scrollXLStarted)
            scrollXL();
        else if (e.pageX > ($(window).width() - 10) && !scrollXRStarted)
            scrollXR();
    }
});

$(".data-container").mouseup(function (e) {
    clearInterval(scrollXLinterval);
    clearInterval(scrollXRinterval);
    scrollXLStarted = false;
    scrollXRStarted = false;
});

$(".alignment").click(function (e) {
    let alignment = $(this).attr("data-type");
    $(".alignment.selected").removeClass("selected");
    $(this).addClass("selected");
    $(".input-cell.selected").css("text-align", alignment);
    updateCellData("alignment", alignment);
});

$("#bold").click(function (e) {
    toggleStyle(this, "bold", "font-weight", "bold");
})

$("#italic").click(function (e) {
    toggleStyle(this, "italic", "font-style", "italic");
})

$("#underlined").click(function (e) {
    toggleStyle(this, "underlined", "text-decoration", "underline");
})

function toggleStyle(ele, property, key, value) {
    if ($(ele).hasClass("selected")) {
        $(ele).removeClass("selected");
        $(".input-cell.selected").css(key, "");
        updateCellData(property, false);
    }
    else {
        $(ele).addClass("selected");
        $(".input-cell.selected").css(key, value);
        updateCellData(property, value);
    }
}

$(".menu-selector").change(function (e) {
    let value = $(this).val();
    let key = $(this).attr("id");
    if (key == "font-family")
        $("font-family").css(key, value);
    if (!isNaN(value))
        value = parseInt(value);
    $(".input-cell.selected").css(key, value);
    updateCellData(key, value);
})


$(".pick-color").colorPick({
    'initialColor': "#abcd",
    'allowRecent': true,
    'recentMax': 5,
    'allowCustomColor': true,
    'palette': ["#1abc9c", "#16a085", "#2ecc71", "#27ae60", "#3498db", "#2980b9", "#9b59b6", "#8e44ad", "#34495e", "#2c3e50", "#f1c40f", "#f39c12", "#e67e22", "#d35400", "#e74c3c", "#c0392b", "#ecf0f1", "#bdc3c7", "#95a5a6", "#7f8c8d"],
    'onColorSelected': function () {
        console.log(this.element);
        console.log(this.element.children()[0]);
        console.log(this.element.children()[1]);
        if ($(this.element.children()[1]).attr("id") == "fill-color") {
            $(".input-cell.selected").css("background-color", this.color);
            $("#fill-color").css("border-bottom", `5px solid ${this.color}`);
            updateCellData("bgcolor", this.color);
        }
        else if ($(this.element.children()[1]).attr("id") == "text-color") {
            $(".input-cell.selected").css("color", this.color);
            $("#text-color").css("border-bottom", `5px solid ${this.color}`);
            updateCellData("color", this.color);
        }
    }
});

$("#fill-color").click(function (e) {
    setTimeout(() => {
        $(this).parent().click();
    }, 10);
});

$("#text-color").click(function (e) {
    setTimeout(() => {
        $(this).parent().click();
    }, 10);
});

function updateCellData(property, value) {
    // console.log(cellData);

    let prevcellData = JSON.stringify(cellData);

    if (value != defaultProperties[property]) {
        $(".input-cell.selected").each(function (index, data) {
            let [rowId, colId] = getrowcol(data);
            // console.log("1");
            // console.log(cellData);
            if (cellData[selectedSheet][rowId - 1] == undefined) {
                cellData[selectedSheet][rowId - 1] = {};
                cellData[selectedSheet][rowId - 1][colId - 1] = { ...defaultProperties };
                cellData[selectedSheet][rowId - 1][colId - 1][property] = value;
            }
            else {
                if (cellData[selectedSheet][rowId - 1][colId - 1] == undefined) {
                    cellData[selectedSheet][rowId - 1][colId - 1] = { ...defaultProperties };
                    cellData[selectedSheet][rowId - 1][colId - 1][property] = value;
                }
                else
                    cellData[selectedSheet][rowId - 1][colId - 1][property] = value;
            }
        });
    }
    else {
        $(".input-cell.selected").each(function (index, data) {
            let [rowId, colId] = getrowcol(data);
            // console.log("2");
            // console.log(cellData);
            if (cellData[selectedSheet][rowId - 1] && cellData[selectedSheet][rowId - 1][colId - 1]) {
                cellData[selectedSheet][rowId - 1][colId - 1][property] = value;
                if (JSON.stringify(cellData[selectedSheet][rowId - 1][colId - 1]) == JSON.stringify(defaultProperties))
                    delete cellData[selectedSheet][rowId - 1][colId - 1];
                if (Object.keys(cellData[selectedSheet][rowId - 1]).length == 0)
                    delete cellData(cellData[selectedSheet][rowId - 1]);
            }
        });
    }

    if (saved && prevcellData != JSON.stringify(cellData))
        saved = false;
}



// ============================== For Sheet Container =========================================


function selectSheet(ele) {
    if (ele && !$(ele).hasClass("selected")) {
        $(".sheet-tab.selected").removeClass("selected");
        $(ele).addClass("selected");
    }

    console.log(cellData);

    let newselectedSheet = $(".sheet-tab.selected").text();
    // console.log(newselectedSheet, selectedSheet);

    if (newselectedSheet == selectedSheet)
        return;
    emptyPreviousSheet();
    selectedSheet = newselectedSheet;
    loadCurrentSheet();
    $("#row-1-col-1").click();
}

function emptyPreviousSheet() {
    let data = cellData[selectedSheet];
    // console.log(selectedSheet, data);
    let rowKeys = Object.keys(data);
    console.log(rowKeys);
    for (let i of rowKeys) {
        let row = parseInt(i);
        let colKeys = Object.keys(data[row]);
        // console.log(colKeys);
        for (let j of colKeys) {
            let col = parseInt(j);
            let cell = $(`#row-${row + 1}-col-${col + 1}`);
            cell.text("");
            cell.css({
                "font-family": "Noto Sans",
                "font-size": "14",
                "background-color": "#fff",
                "color": "",
                "font-weight": "",
                "font-style": "",
                "text-decoration": "",
                "text-align": "left"
            });
        }
    }
}

function loadCurrentSheet() {
    let data = cellData[selectedSheet];
    let rowKeys = Object.keys(data);
    // console.log(rowKeys);
    for (let i of rowKeys) {
        let row = parseInt(i);
        let colKeys = Object.keys(data[row]);
        for (let j of colKeys) {
            let col = parseInt(j);
            // console.log(row);
            // console.log(col);
            let cell = $(`#row-${row + 1}-col-${col + 1}`);
            cell.text(data[row][col].text);
            cell.css({
                "font-family": data[row][col]["font-family"],
                "font-size": data[row][col]["font-size"],
                "background-color": data[row][col]["bgcolor"],
                "color": data[row][col].color,
                "font-weight": data[row][col].bold ? "bold" : "none",
                "font-style": data[row][col].italic ? "italic" : "none",
                "text-decoration": data[row][col].underline ? "underline" : "none",
                "text-align": data[row][col].alignment
            });
        }
    }
}


$(".container").click(function (e) {
    $(".sheet-options-modal").remove();
});

function renameSheet() {
    let newSheetName = $(".sheet-modal-input").val();
    if (newSheetName && !Object.keys(cellData).includes(newSheetName)) {
        saved = false;
        cellData[newSheetName] = cellData[selectedSheet];
        delete cellData[selectedSheet]
        selectedSheet = newSheetName;
        $(".sheet-tab.selected").text(newSheetName);
        $(".sheet-modal-parent").remove();
    }
    else {
        $(".rename-error").remove();
        $(".sheet-modal-input-container").append(`<div class="rename-error"> Sheet name is either empty or already exists`);
    }
}

function deleteSheet() {
    $(".sheet-modal-parent").remove();
    let sheetIndex = Object.keys(cellData).indexOf(selectedSheet);
    let currSelectedSheet = $(".sheet-tab.selected");
    if (sheetIndex == 0)
        selectSheet(currSelectedSheet.next()[0]);
    else
        selectSheet(currSelectedSheet.prev()[0]);

    delete (cellData[currSelectedSheet.text()]);
    currSelectedSheet.remove();
    totalSheets--;
    // console.log(selectedSheet);
}

function addSheetEvents() {
    $(".sheet-tab.selected").on("contextmenu", function (e) {    // contextmenu comes when we right click somewhere

        // Preventing default action of opening the context menu
        e.preventDefault();

        // Selecting the sheetwhere contex menu is opened
        selectSheet(this);

        $(".sheet-options-modal").remove();
        let modal = $(`<div class="sheet-options-modal">
                            <div class="option sheet-rename">Rename</div>
                            <div class="option sheet-delete">Delete</div>
                        </div>`);
        modal.css({ "left": e.pageX });
        $(".container").append(modal);

        // Adding Rename Modal in the container

        $(".sheet-rename").click(function (e) {
            let renameModal = $(`<div class="sheet-modal-parent">
                                    <div class="sheet-rename-modal">
                                        <div class="sheet-modal-title">Rename Sheet</div>
                                        <div class="sheet-modal-input-container">
                                            <span class="sheet-modal-input-title">Rename Sheet to:</span>
                                            <input class="sheet-modal-input" type="text" />
                                        </div>
                                        <div class="sheet-modal-confirmation">
                                            <div class="button yes-button">OK</div>
                                            <div class="button no-button">CANCEL</div>
                                        </div>
                                    </div>
                                </div>`);
            $(".container").append(renameModal);
            $(".sheet-modal-input").focus();
            $(".no-button").click(function (e) {
                $(".sheet-modal-parent").remove();
            });
            $(".yes-button").click(function (e) {
                renameSheet();
            });

            $(".sheet-modal-input").keypress(function (e) {
                if (e.key == "Enter")
                    renameSheet();
            });
        });

        // Adding Delete Modal in the Container

        $(".sheet-delete").click(function (e) {
            if (totalSheets > 1) {
                let deleteModal = $(`<div class="sheet-modal-parent">
                                        <div class="sheet-delete-modal">
                                            <div class="sheet-modal-title">${selectedSheet}</div>
                                            <div class="sheet-modal-detail-container">
                                                <span class="sheet-modal-detail-title">Are You Sure?</span>
                                            </div>
                                            <div class="sheet-modal-confirmation">
                                                <div class="button yes-button">
                                                    <div class="material-icons">delete</div> DELETE
                                                </div>
                                                <div class="button no-button">CANCEL</div>
                                            </div>
                                        </div>
                                    </div>`);
                $(".container").append(deleteModal);
                $(".no-button").click(function (e) {
                    $(".sheet-modal-parent").remove();
                });
                $(".yes-button").click(function (e) {
                    deleteSheet();
                });
                // $(this).keypress("Enter", function(e){
                if (this.key == "Enter") {
                    console.log("Enter");
                    deleteSheet();
                }
                // });
            }
            else
                alert("Cannot Delete a Single Sheet");
        });
    });

    // Adding event listener of click() on all the divs of ".sheet-tab"
    // NOTE:- Event Listners are attatched to the divs, NOT on the classes.
    $(".sheet-tab.selected").click(function (e) {
        selectSheet(this);
    });
}

addSheetEvents();

$(".add-sheet").click(function (e) {
    lastlyAddedSheet++;
    totalSheets++;
    saved = false;
    cellData[`Sheet ${lastlyAddedSheet}`] = {};
    $(".sheet-tab.selected").removeClass("selected");
    $(".sheet-tab-container").append(`<div class="sheet-tab selected">Sheet ${lastlyAddedSheet}</div>`);
    selectSheet();
    addSheetEvents();
    $(".sheet-tab.selected")[0].scrollIntoView();
});

$(".left-scroller, .right-scroller").click(function (e) {
    let keyArray = Object.keys(cellData);
    let curridx = keyArray.indexOf(selectedSheet);

    console.log(this);

    if ((curridx != 0) && ($(this).text() == "keyboard_arrow_left"))
        selectSheet($(".sheet-tab.selected").prev()[0]);
    else if ((curridx != keyArray.length - 1) && ($(this).text() == "keyboard_arrow_right"))
        selectSheet($(".sheet-tab.selected").next()[0]);

    $(".sheet-tab.selected")[0].scrollIntoView();
});


// ===================================Cut Copy Paste====================================================================

// let clipboard = {startCell : [], cellData : {}};

// $("#copy").click(function(e)
// {
//     clipboard.startCell = getrowcol($(".input-cell.selected")[0]);
//     $(".input-cell.selected").each(function(index, data)
//     {
//         let [row, col] = getrowcol(data);
//         if(cellData[selectedSheet][row-1] && cellData[selectedSheet][row-1][col-1])
//         {
//             if(!clipboard.cellData[row])
//                 clipboard,cellData[row] = {};
//             clipboard.cellData[row][col] = {...cellData[selectedSheet][row-1][col-1]};
//         }
//     });
//     console.log(clipboard);
// });

// $("#cells").keypress("ctrl+x", function(e)
// {
//     $(".input-cell.selected").each(function(index, data)
//     {
//         let [row, col] = getrowcol(data);
//         clipboard[row-1] = [];
//         clipboard[row-1].append(col-1);
//         clipboard[row-1][col-1] = cellData[selectedSheet][row-1][col-1];
//         cellData[selectedSheet][row-1][col-1] = [];
//         let cell = $(`#row-${row}-col-${col}`);
//         cell.css({
//             "font-family": "Noto Sans",
//                 "font-size": "14",
//                 "background-color": "#fff",
//                 "color": "",
//                 "font-weight": "",
//                 "font-style": "",
//                 "text-decoration": "",
//                 "text-align": "left"
//         });
//     });
// });

// $("#cells").keypress("ctrl+v", function(e)
// {
//     for(let i of clipboard)
//     {
//         for(let j of clipboard[i])
//     }
// });



// ================================================Fie Modal========================================================

$(".menu-file").click(function (e) {
    let fileModal = $(`<div class="file-modal">
                            <div class="file-options-modal">
                                <div class="close">
                                    <div class="material-icons close-icon">arrow_circle_down</div>
                                    <div>Close</div>
                                </div>
                                <div class="new">
                                    <div class="material-icons new-icon">insert_drive_file</div>
                                    <span>New</span>
                                </div>
                                <div class="open">
                                    <div class="material-icons open-icon">folder_open</div>
                                    <span>Open</span>
                                </div>
                                <div class="save">
                                    <div class="material-icons save-icon">save</div>
                                    <span>Save</span>
                                </div>
                            </div>
                            <div class="file-recent-modal"></div>
                            <div class="file-transparent-modal"></div>
                        </div>`);

    // Opening the file modal
    $(".container").append(fileModal);
    fileModal.animate({
        width: "100vw"
    }, 250);

    // Closing the File Modal
    $(".close, .file-transparent-modal, .new, .save, .open").click(function (e) {
        fileModal.animate({
            width: "0vw"
        }, 250);
        setTimeout(function (e) {
            $(".file-modal").remove();
        }, 250);

    });

    // Making a new file
    $(".new").click(function (e) {
        if (saved)
            newFile();
        else {
            let saveModal = $(`<div class="sheet-modal-parent">
                                    <div class="sheet-delete-modal">
                                        <div class="sheet-modal-title">${$(".title").text()}</div>
                                        <div class="sheet-modal-detail-container">
                                            <span class="sheet-modal-detail-title">Do You want to Save changes?</span>
                                        </div>
                                        <div class="sheet-modal-confirmation">
                                            <div class="button yes-button">YES</div>
                                            <div class="button no-button">NO</div>
                                        </div>
                                    </div>
                                </div>`);
            $(".container").append(saveModal);
            $(".yes-button").click(function (e) {
                $(".sheet-modal-parent").remove();
                saveFile(true);
            });
            $(".no-button").click(function (e) {
                // saveFile();
                $(".sheet-modal-parent").remove();
                newFile();
            });
        }
    });
    $(".save").click(function (e) {
        if(!saved)
            saveFile();
    });
    $(".open").click(function(e){
        openFile();
    });
});


function newFile() {
    emptyPreviousSheet();
    cellData = { "Sheet 1": {} };
    $(".sheet-tab").remove();
    $(".sheet-tab-container").append(`<div class="sheet-tab selected">Sheet 1</div>`);
    $(".title").text("Sheet 1 - Excel");
    selectedSheet = "Sheet 1";
    totalSheets = 1;
    $("#row-1-col-1").click();
    $(".file-modal").remove();
    addSheetEvents();
}

function saveFile(newClicked) {
    let saveModal = $(`<div class="sheet-modal-parent">
                            <div class="sheet-rename-modal">
                                <div class="sheet-modal-title">Save File</div>
                                <div class="sheet-modal-input-container">
                                    <span class="sheet-modal-input-title">File Name:</span>
                                    <input class="sheet-modal-input" type="text" value="${$(".title").text()}" />
                                </div>
                                <div class="sheet-modal-confirmation">
                                    <div class="button yes-button">SAVE</div>
                                    <div class="button no-button">CANCEL</div>
                                </div>
                            </div>
                        </div>`);
    console.log("save");
    $(".container").append(saveModal);

    $(".sheet-modal-input").focus();
    $(".sheet-modal-input").select();

    $(".yes-button").click(function (e) {
        $(".title").text($(".sheet-modal-input").val());
        let a = document.createElement("a");
        a.href = `data:applications/json,${encodeURIComponent(JSON.stringify(cellData))}`;
        a.download = $(".title").text() + ".json";
        $(".container").append(a);
        a.click();
        a.remove();
        saved = true;
    });
    $(".yes-button, .no-button").click(function (e) {
        if(newClicked)
            newFile();
        $(".sheet-modal-parent").remove();
    });
}

function openFile()
{
    let inputFile = $(`<input type="file" accept="application/json" />`);
    $(".contaier").append(inputFile);
    inputFile.click();
    inputFile.change(function(e){
        console.log(e);
        let file = e.target.files[0];
        $(".title").text(file.name.split(".json")[0]);
        let reader = new FileReader();
        reader.readAsText(file);
        reader.onload = () =>{
            console.log(reader.result);
        }
    });
}