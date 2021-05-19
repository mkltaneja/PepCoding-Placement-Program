// Adding the Perfect Scrollbar
const ps = new PerfectScrollbar(`#cells`,{
    wheelSpeed: 1
});

// Naming rows and columns
for(let i = 1; i <= 100; i++)
{
    let str = "";
    let n = i;

    while(n > 0)
    {
        let rem = n%26;
        if(rem == 0)
        {
            str = "Z" + str;
            n = Math.floor(n/26) - 1;
        }
        else
        {
            str = String.fromCharCode((rem - 1) + 65) + str;
            n = Math.floor(n/26);
        }
    }
    $("#columns").append(`<div class="column-name">${str}</div>`);
    $("#rows").append(`<div class="row-name">${i}</div>`);
}

let cellData = {
    "Sheet 1" : {}
};

let selectedSheet = "Sheet 1";
let totalSheets = 1;
let lastlyAddedSheet = 1;

let defaultProperties = {
    "font-family" : "Noto Sans",
    "font-size" : 14,
    "text" : "",
    "bold" : false,
    "italic" : false,
    "underlined" : false,
    "alignment" : "left",
    "color" : "444",
    "bgcolor" : "#fff"
};

// Constructing cells
for(let i = 1; i <= 100; i++)
{
    let row = $(`<div class="cell-row"></div>`);
    for(let j = 1; j <= 100; j++)
        row.append(`<div id="row-${i}-col-${j}" class="input-cell" contenteditable="false"></div>`);
    $("#cells").append(row);
}

// For scrolling Rows and columns along with the cells
$("#cells").scroll(function(e){
    $("#rows").scrollTop(this.scrollTop);
    $("#columns").scrollLeft(this.scrollLeft);
});

// Making cell editable by double clicking
$(".input-cell").dblclick(function(e){
    $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    $(this).attr("contenteditable", "true");
    $(this).focus();
});

// Getting row and columns of the selected cell
function getrowcol(ele)
{
    let id = $(ele).attr("id");
    let idArray = id.split("-");
    let rowId = parseInt(idArray[1]);
    let colId = parseInt(idArray[3]);

    // console.log(ele);

    return [rowId, colId];
}

// Getting Top, Bottom, Right, Left of the selected cell
function getTopBottomLeftRight(rowId, colId)
{
    console.log(rowId);
    console.log(colId);

    let topCell = $(`#row-${rowId-1}-col-${colId}`);
    let bottomCell = $(`#row-${rowId+1}-col-${colId}`);
    let leftCell = $(`#row-${rowId}-col-${colId-1}`);
    let rightCell = $(`#row-${rowId}-col-${colId+1}`);

    console.log(topCell);
    console.log(bottomCell);
    console.log(leftCell);
    console.log(rightCell);

    return [topCell, bottomCell, leftCell, rightCell];
}

// Operations after one is selected and making more than one cell selectable
function selectCell(ele, e, topCell, bottomCell, leftCell, rightCell)
{
    if(e.ctrlKey)
    {
        let topSelected;
        if(topCell)
            topSelected = topCell.hasClass("selected");
        
        let bottomSelected;
        if(bottomCell)
            bottomSelected = bottomCell.hasClass("selected");
        
        let leftSelected;
        if(leftCell)
            leftSelected = leftCell.hasClass("selected");
        
        let rightSelected;
        if(rightCell)
            rightSelected = rightCell.hasClass("selected");

        if(topSelected)
        {
            $(ele).addClass("top-selected");
            (topCell).addClass("bottom-selected");
        }

        if(bottomSelected)
        {
            $(ele).addClass("bottom-selected");
            (bottomCell).addClass("top-selected");
        }
        
        if(leftSelected)
        {
            $(ele).addClass("left-selected");
            (leftCell).addClass("right-selected");
        }
        
        if(rightSelected)
        {
            $(ele).addClass("right-selected");
            (rightCell).addClass("left-selected");
        }
    }
    else 
        $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    $(ele).addClass("selected");
}

// For Unselecting the chosen cell - removing the "selected" classes
function unselectCell(ele, e, topCell, bottomCell, leftCell, rightCell)
{
    if($(ele).attr("contenteditable") == "false")
    {
        if($(ele).hasClass("top-selected"))
            topCell.removeClass("bottom-selected");
        
        if($(ele).hasClass("bottom-selected"))
            bottomCell.removeClass("top-selected");
        
        if($(ele).hasClass("left-selected"))
           leftCell.removeClass("right-selected");
    
        if($(ele).hasClass("right-selected"))
            rightCell.removeClass("left-selected");
        
        $(ele).removeClass("selected top-selected bottom-selected left-selected right-selected");
    }
}

// After single clicking a cell
$(".input-cell").click(function(e){
    $(this).attr("contenteditable", "false");
    let [rowId, colId] = getrowcol(this);
    let [topCell, bottomCell, leftCell, rightCell] = getTopBottomLeftRight(rowId, colId);

    if($(this).hasClass("selected") && e.ctrlKey)
        unselectCell(this, e, topCell, bottomCell, leftCell, rightCell);
    else
        selectCell(this, e, topCell, bottomCell, leftCell, rightCell);
    
    updateCellData("text", $(this).text());
});

// If we a cell without ctrl Key the previous selected cell(s) become blur
$(".input-cell").blur(function(e){
    $(this).attr("contenteditable", "false");
});

function selectAllbetween(startCell, endCell)
{
    $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    for(let i = Math.min(startCell.rowId, endCell.rowId); i < Math.max(startCell.rowId, endCell.rowId); i++)
    {
        for(let j = Math.min(startCell.colId, endCell.colId); j < Math.max(startCell.colId, endCell.colId); j++)
        {
            let [top, bottom, left, right] = getTopBottomLeftRight(i, j);
            console.log($(`#row-${i}-col-${j}`)[0]);
            selectCell($(`#row-${i}-col-${j}`)[0], {"ctrlKey" : true}, top, bottom, left, right);
        }
    }
}

let startCellSelected = false;
let startCell = {};
let endCell = {};
$(".input-cell").mousemove(function(e){
    e.preventDefault();
    if(e.buttons == 1)
    {
        if(!startCellSelected)
        {
            let [rowId, colId] = getrowcol(this);
            startCell = {"rowId": rowId, "colId": colId};
            startCellSelected = true;
            selectAllbetween(startCell, endCell);
            console.log(startCell, endCell);
        }
    }
    else
        startCellSelected = false;
});

$(".input-cell").mouseenter(function(e){
    if(e.buttons == 1)
    {
        if(e.pageX > 10 && scrollXLStarted)
        {
            clearInterval(scrollXLinterval);
            scrollXLStarted = false;
        }
        else if(e.pageX < ($(window).width() - 10) && scrollXRStarted)
        {
            clearInterval(scrollXRinterval);
            scrollXRStarted = false;
        }

        let [rowId, colId] = getrowcol(this);
        endCell = {"rowId": rowId, "colId": colId};
        selectAllbetween(startCell, endCell);
    }
});

let scrollXLStarted = false;
let scrollXRStarted = false;
let scrollXLinterval;
let scrollXRinterval;

function scrollXL()
{
    scrollXLStarted = true;
    scrollXLinterval = setInterval(() =>{
        $("#cells").scrollLeft($("#cells").scrollLeft() - 100)
    }, 100);
}

function scrollXR()
{
    scrollXRStarted = true;
    scrollXRinterval = setInterval(() =>{
        $("#cells").scrollLeft($("#cells").scrollLeft() - 100)
    }, 100);
}

$(".data-container").mousemove(function(e){
    e.preventDefault();
    if(e.buttons == 1)
    {
        if(e.pageX < (10) && !scrollXLStarted)
            scrollXL();
        else if(e.pageX > ($(window).width() - 10) && !scrollXRStarted)
            scrollXR();
    }
});

$(".data-container").mouseup(function(e){
    clearInterval(scrollXLinterval);
    clearInterval(scrollXRinterval);
    scrollXLStarted = false;
    scrollXRStarted = false;
});

$(".alignment").click(function(e){
    let alignment = $(this).attr("data-type");
    $(".alignment.selected").removeClass("selected");
    $(this).addClass("selected");
    $(".input-cell.selected").css("text-align", alignment);
    updateCellData("alignment", alignment);
});

$("#bold").click(function(e){
    setStyle(this, "bold", "font-weight", "bold");
})

$("#italic").click(function(e){
    setStyle(this, "italic", "font-style", "italic");
})

$("#underlined").click(function(e){
    setStyle(this, "underlined", "text-decoration", "underline");
})

function setStyle(ele, property, key, value)
{
    if($(ele).hasClass("selected"))
    {
        $(ele).removeClass("selected");
        $(".input-cell.selected").css(key, "");
        updateCellData(property, false);
    }
    else 
    {
        $(ele).addClass("selected");
        $(".input-cell.selected").css(key, value);
        updateCellData(property, value);
    }
}

$(".menu-selector").change(function(e){
    let value = $(this).val();
    let key = $(this).attr("id");
    if(key == "font-family")
        $("font-family").css(key, value);
    if(!isNaN(value))
        value = parseInt(value);
    $(".input-cell.selected").css(key, value);
    updateCellData(key, value);
})


// $(".pick-color").colorPick({
//     'initialColor': "#abcd",
//     'allowRecent': true,
//     'recentMax': 5,
//     'allowCustomColor': true,
//     'palette': ["#1abc9c", "#16a085", "#2ecc71", "#27ae60", "#3498db", "#2980b9", "#9b59b6", "#8e44ad", "#34495e", "#2c3e50", "#f1c40f", "#f39c12", "#e67e22", "#d35400", "#e74c3c", "#c0392b", "#ecf0f1", "#bdc3c7", "#95a5a6", "#7f8c8d"],
//     // 'onColorSelected': function () {

//     // }
// })

function updateCellData(property, value)
{
    // console.log(cellData);
    // if(value != defaultProperties[property])
    // {
        $(".input-cell.selected").each(function(index, data){
            let [rowId, colId] = getrowcol(data);
            // console.log("1");
            // console.log(cellData);
            if(cellData[selectedSheet][rowId-1] == undefined)
            {
                cellData[selectedSheet][rowId-1] = {};
                cellData[selectedSheet][rowId-1][colId-1] = {...defaultProperties};
                cellData[selectedSheet][rowId-1][colId-1][property] = value;
            }
            else
            {
                if(cellData[selectedSheet][rowId-1][colId-1] == undefined)
                {
                    cellData[selectedSheet][rowId-1][colId-1] = {...defaultProperties};
                    cellData[selectedSheet][rowId-1][colId-1][property] = value;
                }
                else
                    cellData[selectedSheet][rowId-1][colId-1][property] = value;
            }
        });
    // }
    // else
    // {
    //     $(".input-cell.selected").each(function(index, data){
    //         let [rowId, colId] = getrowcol(data);
    //         // console.log("2");
    //         // console.log(cellData);
    //         if(cellData[selectedSheet][rowId-1][colId-1] != undefined)
    //         {
    //             cellData[selectedSheet][rowId-1][colId-1][property] = value;
    //             if(JSON.stringify(cellData[selectedSheet][rowId-1][colId-1]) == JSON.stringify(defaultProperties))
    //                 delete cellData[selectedSheet][rowId-1][colId-1];
    //         }
    //     });
    // }
}

// function changeHeader([rowId, colId])
// {
//     let data = 
// }



// $(".data-container").click(function(e){
//     $(".sheet-options-modal").remove();
// });

// function addSheetEvents()
// {
//     $(".sheet-tab").on("contextmenu", function(e){
//         e.preventDefault();
//         $(".sheet-options-modal").remove();
//         let modal = $(`<div class="sheet-options-modal">
//                         <div class="option-sheet-rename">Rename</div>
//                         <div class="option-sheet-delete">Delete</div>
//                     </div>`);
//         modal.css({"left": e.pageX});
//         $(".data-container").append(modal);
//     });
//     $(".sheet-tab").click(function(e){
//         $(".sheet-tab.selected").removeClass("selected");
//         $(this).addClass("selected");
//         selectSheet();
//     });
// }

// addSheetEvents();

$(".add-sheet").click(function(e){
    lastlyAddedSheet++;
    totalSheets++;
    cellData[`Sheet ${lastlyAddedSheet}`] = {};
    $(".sheet-tab.selected").removeClass("selected");
    $(".sheet-tab-container").append(`<div class="sheet-tab selected">Sheet ${lastlyAddedSheet}</div>`);
    // selectSheet();
    // addSheetEvents();
});

$(".sheet-tab").click(function(e)
{
    emptyPreviousSheet();
    // $(".sheet-tab.selected").removeClass("selected");
    // $(this).addClass("selected");
    // console.log(this);
    // // $();
    // selectSheet();
});

function selectSheet()
{
    emptyPreviousSheet();
    selectedSheet = $(".sheet-tab.selected").text();
    loadCurrentSheet();
}

function emptyPreviousSheet()
{
    let data = cellData[selectedSheet];
    let rowKeys = Object.keys(data);
    console.log(rowKeys);
    for(let i of rowKeys)
    {
        let colKeys = Object.keys(rowKeys);
        console.log(colKeys);
        for(let j of colKeys)
        {
            let row = parseInt(i);
            let col = parseInt(j);
            console.log(row);
            console.log(col);
            let cell = $(`#row-${row+1}-col-${col+1}`);
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

function loadCurrentSheet()
{
    let data = cellData[selectedSheet];
    let rowKeys = Object.keys(data);
    // console.log(rowKeys);
    for(let i of rowKeys)
    {
        let colKeys = Object.keys(rowKeys);
        for(let j of colKeys)
        {
            let row = parseInt(i);
            let col = parseInt(j);
            console.log(row);
            console.log(col);
            let cell = $(`#row-${row+1}-col-${col+1}`);
            cell.text("");
            cell.css({
                "font-family": data[row][col]["font-family"],
                "font-size": data[row][col]["font-size"],
                "background-color": data[row][col]["bgcolor"],
                "color": data[row][col].color,
                "font-weight": data[row][col].bold? "bold" : "none",
                "font-style": data[row][col].italic? "italic" : "none",
                "text-decoration": data[row][col].underline? "underline" : "none",
                "text-align": data[row][col].alignment
            });
        }
    }
}