let turn = 0;

function cellCelect(cell_number) {
    let value = document.getElementById('$cell_number').value;
    if (turn === 0) {
        //Ход игрока1
        switch (value) {
            case(0):
                break;
            case(1):
                function pawn() {
                    //Ход пешки
                    }
                            turn++;
                            break;
            case (2):
            function rook() {
                //ход ладьи
                }
                    turn++;
                    break;
            case (3):
            function horse() {
                //ход конём
                }
                turn++;
                break;
            case (4):
            function bishop() {
                //Ход слона
            }

                turn++;
                break;
            case (5):

            function queen() {
                //Ход королевы
            }

                turn++;
                break;
            case (6):

            function king() {
                //Ход короля
            }

                turn++;
                break;
        }
    }
    if (turn === 1) {
        //Ход игрока2
        switch (value) {
            case(0):
                break;
            case(7):

            function pawn() {
                //Ход пешки
            }

                turn++;
                break;
            case (8):

            function rook() {
                //ход ладьи
            }

                turn++;
                break;
            case (9):

            function horse() {
                //ход конём
            }

                turn++;
                break;
            case (10):

            function bishop() {
                //Ход слона
            }

                turn++;
                break;
            case (11):

            function queen() {
                //Ход королевы
            }

                turn++;
                break;
            case (12):
                    function king() {
                //Ход короля
            }

                turn++;
                break;
        }
    }

}
//Цикл для обработки value иначе. Из массива, который будет передавать Егор. Когда ты будешь соединять наши проги
// Сотри value в divах(или я сотрку) и раскометь этот цикл, который сам все сделает
// egorArr[0-63]
//for (let i = 0; i < 63; i++){
//let value = egorArr[i];
// let value_of_cell = document.getElementbyid(i(ну тип айди клетки == индекс массива));
//value_of_cell.value = egorArr[i];
//}