let turn = 0,
    boardData = new Array(64),
    memoryData = [0, 0, 0, 0, 0, 0, 0],
    selectedFigureCellId = 90,
    selectedCellId = 90,
    gameStatus = 0;

const cellCollection = document.getElementsByClassName("cell");

function printFigures(dataArr) {
    for (let i = 0; i < 64; i++) {
        switch (dataArr[i]) {
            case 0:
                cellCollection[i].innerHTML = "";
                break;
            case 1:
                cellCollection[i].innerHTML = "<div class = 'figure white-pawn-figure'></div>";
                break;
            case 2:
                cellCollection[i].innerHTML = "<div class = 'figure white-rook-figure'></div>";
                break;
            case 3:
                cellCollection[i].innerHTML = "<div class = 'figure white-knight-figure'></div>";
                break;
            case 4:
                cellCollection[i].innerHTML = "<div class = 'figure white-bishop-figure'></div>";
                break;
            case 5:
                cellCollection[i].innerHTML = "<div class = 'figure white-queen-figure'></div>";
                break;
            case 6:
                cellCollection[i].innerHTML = "<div class = 'figure white-king-figure'></div>";
                break;
            case 7:
                cellCollection[i].innerHTML = "<div class = 'figure black-pawn-figure'></div>";
                break;
            case 8:
                cellCollection[i].innerHTML = "<div class = 'figure black-rook-figure'></div>";
                break;
            case 9:
                cellCollection[i].innerHTML = "<div class = 'figure black-knight-figure'></div>";
                break;
            case 10:
                cellCollection[i].innerHTML = "<div class = 'figure black-bishop-figure'></div>";
                break;
            case 11:
                cellCollection[i].innerHTML = "<div class = 'figure black-queen-figure'></div>";
                break;
            case 12:
                cellCollection[i].innerHTML = "<div class = 'figure black-king-figure'></div>";
                break;
        }
    }
}

function createStartData() {
    boardData.fill(0);
    boardData[56] = 2;
    boardData[57] = 3;
    boardData[58] = 4;
    boardData[59] = 5;
    boardData[60] = 6;
    boardData[61] = 4;
    boardData[62] = 3;
    boardData[63] = 2;
    boardData.fill(1, 48, 56);
    boardData.fill(7, 8, 16);
    boardData[0] = 8;
    boardData[1] = 9;
    boardData[2] = 10;
    boardData[3] = 11;
    boardData[4] = 12;
    boardData[5] = 10;
    boardData[6] = 9;
    boardData[7] = 8;
    printFigures(boardData);
}

function cellSelect(cellId) {
    let cellFigureId = boardData[cellId];
    console.log(cellFigureId);
    if (turn === 0) {
        if (cellFigureId < 7 && cellFigureId !== 0) {
            selectedFigureCellId = cellId;
        } else if (selectedFigureCellId !== 90) {
            selectedCellId = cellId;
        }
    } else {
        if (cellFigureId > 6) {
            selectedFigureCellId = cellId;
        } else if (selectedFigureCellId !== 90) {
            selectedCellId = cellId;
        }
    }
    highlightSelection();
}

function highlightSelection() {
    for (let i = 0; i < cellCollection.length; i++) {
        cellCollection[i].classList.remove("cell-highlighted", "figure-cell-highlighted")
    }
    if (selectedCellId !== 90) cellCollection[selectedCellId].classList.add("cell-highlighted");
    if (selectedFigureCellId !== 90) cellCollection[selectedFigureCellId].classList.add("figure-cell-highlighted");
}

const accept_button = document.getElementById('accept');
const alternative_button = document.getElementById('alt-button');
const chessTable = document.getElementById('chess-table');
const figureCollection = document.getElementsByClassName('figure');

function changeTurn() {
    if (turn === 0) {
        chessTable.style = 'transform: rotate(180deg)';
        for (let i = 0; i < figureCollection.length; i++) {
            figureCollection[i].classList.add('figure-rotate');
        }
        turn = 1;
    } else {
        chessTable.style = 'transform: rotate(0deg)';
        for (let i = 0; i < figureCollection.length; i++) {
            figureCollection[i].classList.remove('figure-rotate');
        }
        turn = 0;
    }
}

alternative_button.onclick = function () {
    if (gameStatus === 1) {
        selectedCellId = 90;
        selectedFigureCellId = 90;
        turn = 1;
        changeTurn();
        createStartData();
        printFigures(boardData);
        highlightSelection();
    }
}

accept_button.onclick = function () {
    if (gameStatus === 0) {
        accept_button.innerText = "Подтвердить ход";
        alternative_button.innerText = "Начать заново"
        createStartData();
        gameStatus = 1;
    } else {
        boardData = boardData.reverse();
        let processedData = processData([...boardData, (63-selectedFigureCellId), (63-selectedCellId), ...memoryData, 0]);
        boardData = boardData.reverse();
        processedData = processedData.split(',');
        memoryData = processedData.slice(66, 73);
        if(processedData[73] == 1 && selectedFigureCellId !== 90 && selectedFigureCellId !== 90){
            boardData[selectedCellId] = boardData[selectedFigureCellId];
            boardData[selectedFigureCellId] = 0;
            printFigures(boardData);
            changeTurn();
        }
        selectedCellId = 90;
        selectedFigureCellId = 90;
        highlightSelection();
    }
}