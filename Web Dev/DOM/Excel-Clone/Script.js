
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

// Constructing cells
for(let i = 1; i <= 100; i++)
{
    let row = $(`<div class="cell-row"></div>`);
    for(let j = 1; j <= 100; j++)
        row.append(`<div id="row-${i}-col-${j}" class="input-cell" contenteditable="false"></div>`);
    $("#cells").append(row);
}

$("#cells").scroll(function(e){
    $("#rows").scrollTop(this.scrollTop);
    $("#columns").scrollLeft(this.scrollLeft);
});

$(".input-cell").dblclick(function(e){
    $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    $(this).attr("contenteditable", "true");
    $(this).focus();
});

function getrowcol(ele)
{
    let id = $(ele).attr("id");
    let idArray = id.split("-");
    let rowId = parseInt(idArray[1]);
    let colId = parseInt(idArray[3]);

    // console.log(ele);

    return [rowId, colId];
}

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

        // console.log(topSelected);
        // console.log(bottomSelected);
        // console.log(leftSelected);
        // console.log(rightSelected);
        // console.log(topCell);
        // console.log(bottomCell);
        // console.log(leftCell);
        // console.log(rightCell);
        if(topSelected)
        {
            // console.log("TOP");
            $(ele).addClass("top-selected");
            (topCell).addClass("bottom-selected");
        }

        if(bottomSelected)
        {
            // console.log("BOTTOM");
            $(ele).addClass("bottom-selected");
            (bottomCell).addClass("top-selected");
        }
        
        if(leftSelected)
        {
            // console.log("LEFT");
            $(ele).addClass("left-selected");
            (leftCell).addClass("right-selected");
        }
        
        if(rightSelected)
        {
            // console.log("RIGHT");
            $(ele).addClass("right-selected");
            (rightCell).addClass("left-selected");
        }
    }
    else 
        $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    $(ele).addClass("selected");
}

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


$(".input-cell").click(function(e){
    $(this).attr("contenteditable", "false");
    let [rowId, colId] = getrowcol(this);
    // console.log(rowId + " " + colId);
    let [topCell, bottomCell, leftCell, rightCell] = getTopBottomLeftRight(rowId, colId);
    // console.log(topCell);
    // console.log(bottomCell);
    // console.log(leftCell);
    // console.log(rightCell);

    // console.log($(this).hasClass("top-selected"));

    if($(this).hasClass("selected") && e.ctrlKey)
    {
        // console.log("First");
        unselectCell(this, e, topCell, bottomCell, leftCell, rightCell);
    }
    else
    {
        // console.log("Second");
        selectCell(this, e, topCell, bottomCell, leftCell, rightCell);
    }
});

$(".input-cell").blur(function(e){
    $(this).attr("contenteditable", "false");
});

// COPIED

let count = 0;
let startcellSelected = false;
let startCell = {};
let endCell = {};
let scrollXRStarted = false;
let scrollXLStarted = false;
$(".input-cell").mousemove(function (e) {
    e.preventDefault();
    if (e.buttons == 1) {
        if(e.pageX > ($(window).width() - 10) && !scrollXRStarted) {
            scrollXR();
        } else if(e.pageX < (10) && !scrollXLStarted) {
            scrollXL();
        }
        if (!startcellSelected) {
            let [rowId, colId] = getrowcol(this);
            startCell = { "rowId": rowId, "colId": colId };
            selectAllBetweenCells(startCell, startCell);
            startcellSelected = true;
        }
    } else {
        startcellSelected = false;
    }
});

$(".input-cell").mouseenter(function (e) {
    if (e.buttons == 1) {
        if(e.pageX < ($(window).width() - 10) && scrollXRStarted) {
            clearInterval(scrollXRInterval);
            scrollXRStarted = false;
        }

        if(e.pageX > 10 && scrollXLStarted) {
            clearInterval(scrollXLInterval);
            scrollXLStarted = false;
        }
        let [rowId, colId] = getrowcol(this);
        endCell = { "rowId": rowId, "colId": colId };
        selectAllBetweenCells(startCell, endCell);
    }
})

function selectAllBetweenCells(start, end) {
    $(".input-cell.selected").removeClass("selected top-selected bottom-selected left-selected right-selected");
    for (let i = Math.min(start.rowId, end.rowId); i <= Math.max(start.rowId, end.rowId); i++) {
        for (let j = Math.min(start.colId, end.colId); j <= Math.max(start.colId, end.colId); j++) {
            let [topCell, bottomCell, leftCell, rightCell] = getTopBottomLeftRight(i, j);
            selectCell($(`#row-${i}-col-${j}`)[0], { "ctrlKey": true }, topCell, bottomCell, leftCell, rightCell);
        }
    }
}

let scrollXRInterval;
let scrollXLInterval;
function scrollXR() {
    scrollXRStarted = true;
    scrollXRInterval =  setInterval(() => {
        $("#cells").scrollLeft($("#cells").scrollLeft() + 100);
    }, 100);
}


function scrollXL() {
    scrollXLStarted = true;
    scrollXLInterval =  setInterval(() => {
        $("#cells").scrollLeft($("#cells").scrollLeft() - 100);
    }, 100);
}

$(".data-container").mousemove(function(e){
    e.preventDefault();
    if (e.buttons == 1) {
        if(e.pageX > ($(window).width() - 10) && !scrollXRStarted) {
            scrollXR();
        } else if(e.pageX < (10) && !scrollXLStarted) {
            scrollXL();
        }
    }
});

$(".data-container").mouseup(function(e) {
    clearInterval(scrollXRInterval);
    clearInterval(scrollXLInterval);
    scrollXRStarted = false;
    scrollXLStarted = false;
});

// function selectAllbetween(startCell, endCell)
// {

// }

// let startCellSelected = false;
// let startCell = {};
// let endCell = {};
// $(".input-cell").mousemove(function(e){
//     if(e.buttons == 1)
//     {
//         if(!startCellSelected)
//         {
//             let [rowId, colId] = getrowcol(this);
//             startCell = {"rowId": rowId, "colId": colId};
//             startCellSelected = true;
//         }
//         else 
//         {
//             let [rowId, colId] = getrowcol(this);
//             endCell = {"rowId": rowId, "colId": colId};
//             selectAllbetween(startCell, endCell);
//         }
//         console.log(startCell, endCell);
//     }
//     else
//         startCellSelected = false;
// })



$(".alignment").click(function(e){
    
})