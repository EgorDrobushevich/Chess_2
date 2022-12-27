#include<iostream>


//Фунция проверки возможности походить пешкой ( 0 - нет, 1 - шаг вперёд, 2 - два шага вперёд, 3 - взятие фигуры, 4 - взятие пешки на проходе)
int proverka_peshki_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((((x_pos) == (x_new_pos)) && ((y_new_pos - y_pos == 1) || (y_new_pos - y_pos == 2)) || ((abs(x_pos - x_new_pos) == 1) && (y_new_pos - y_pos == 1))) && ((arr[y_new_pos][x_new_pos] > 6) || (arr[y_new_pos][x_new_pos] == 0))) {				//Проверка на валидность хода (ходит вперёд и не дальше одной клетки влево/вправо)
		if (((x_pos) == (x_new_pos)) && ((y_new_pos - y_pos == 1) || (y_new_pos - y_pos == 2))) { //Попытка походить
			if (arr[y_new_pos][x_new_pos] == 0) { //Проверка возможности стать на желаемую клетку
				if ((y_new_pos - y_pos == 2) && (y_pos == 2) && (arr[x_pos][y_pos + 1] == 0)) { //Проверка варианта ходьбы (две или одна клетка)
					return 2;
				}
				else {
					if (y_new_pos - y_pos == 1) {
						return 1;
					}
					else {
						return 0;
					}
				}
			}
			else {
				return 0;
			}
		}
		else {
			if (1 - arr[y_new_pos][x_new_pos] < -5) { // Проверка на возможность классического взятия фигуры
				return 3;
			}
			else {
				if ((arr[y_new_pos][x_new_pos] == 0) && (((arr[y_pos][x_new_pos]) == 7) && (x_pos == 5))) { // Проверка на возможность взятия пешки на проходе
					return 4;
				}
				else {
					return 0;
				}
			}
		}
	}
	else return 0;
}



//Данная функция осуществляет проверку валидности хода белой ладьёй без учёта возможности шаха (0-нет, 1 - просто ход, 2 - взятие фигуры )
int proverka_ladii_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((x_pos == x_new_pos) || (y_pos == y_new_pos)) {//Ходит ли вдоль одной линии
		if (x_pos == x_new_pos) {//Ходит ли вдоль y
			if (y_pos < y_new_pos) { //Ходит назад или вперёд 
				for (int i = y_pos + 1; i <= y_new_pos; i++) {
					if (arr[i][x_pos] == 0) { // если клетка пустая
						if (y_new_pos == i) { // если это последняя клетка
							return 1;
						}
					}
					else {
						if ((arr[y_new_pos][x_new_pos] > 6) && (y_new_pos == i)) { //если это последняя клетка и там чёрная фигура
							return 2;
						}
						else {
							return 0;				//если это не последняя и не пустая клетка
						}
					}
				}
			}
		}
		else {
			for (int i = y_pos - 1; i >= y_new_pos; i--) {
				if (arr[i][x_pos] == 0) { // если клетка пустая
					if (y_new_pos == i) { // если это последняя клетка
						return 1;
					}
				}
				else {
					if ((arr[y_new_pos][x_new_pos] > 6) && (y_new_pos == i)) { //если это последняя клетка и там чёрная фигура
						return 2;
					}
					else {
						return 0;				//если это не последняя и не пустая клетка
					}
				}
			}
		}
	}
	else {
		if (x_pos < x_new_pos) { //Ходит вправо или влево 
			for (int j = x_pos + 1; j <= x_new_pos; j++) {
				if (arr[y_pos][j] == 0) { // если клетка пустая
					if (x_new_pos == j) { // если это последняя клетка
						return 1;
					}
				}
				else {
					if ((arr[y_new_pos][x_new_pos] > 6) && (x_new_pos == j)) { //если это последняя клетка и там чёрная фигура
						return 2;
					}
					else {
						return 0;				//если это не последняя и не пустая клетка
					}
				}
			}
		}
		else {
			for (int j = x_pos - 1; j >= x_new_pos; j--) {
				if (arr[y_pos][j] == 0) { // если клетка пустая
					if (x_new_pos == j) { // если это последняя клетка
						return 1;
					}
				}
				else {
					if ((arr[y_new_pos][x_new_pos] > 6) && (x_new_pos == j)) { //если это последняя клетка и там чёрная фигура
						return 2;
					}
					else {
						return 0;				//если это не последняя и не пустая клетка
					}
				}
			}
		}
	}
}

//Проверка валидности хода конём ( 0 - нет, 1 - просто ход, 2 - взятие фигуры )
int proverka_khon_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((abs(x_pos - x_new_pos) + abs(y_pos - y_new_pos) == 3) && (x_new_pos != x_pos) && (y_new_pos != y_pos)) {//Проверка клетки куда хотим походить
		if (arr[y_new_pos][x_new_pos] == 0) {//Пустая ли клетка
			return 1;
		}
		else {
			if (arr[y_new_pos][x_new_pos] > 6) {//Чёрная ли фигура там
				return 2;
			}
			else {
				return 0;
			}
		}
	}
}

//Проверка валидности хода слоном ( 0 - нет, 1 - просто ход, 2 - взятие фигуры )
int proverka_slon_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	int difference = y_pos - x_pos;
	int new_difference = y_new_pos - x_new_pos;
	int sum = y_pos + x_pos;
	int new_sum = y_new_pos + x_new_pos;

	if (((difference == new_difference)||(sum==new_sum))&&((sum%2)==(new_sum%2))) {//Проверка на вхождение в диапазон допустимых клеток
		if (y_new_pos - y_pos>0) {// Вверх ли по у
			if (x_new_pos - x_pos > 0) {// Вправо ли по х
				for (int i = y_pos + 1, int j = x_pos + 1; i < y_new_pos; i++, j++) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
			else { // влево по х
				for (int i = y_pos + 1, int j = x_pos - 1; i < y_new_pos; i++, j--) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
		}
		else { // вниз по у
			if (x_new_pos - x_pos > 0) { // вправо
				for (int i = y_pos - 1, int j = x_pos + 1; i > y_new_pos; i--, j++) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
			else { // влево
				for (int i = y_pos - 1, int j = x_pos - 1; i > y_new_pos; i--, j--) {
					if (arr[i][j] != 0) { 
						return 0;
					}
				}
			}
		}
		if (arr[y_new_pos][x_new_pos] > 6) { //проверка конечной клетки на чёрные фигуры в ней
			return 2;
		}
		else {
			if (arr[y_new_pos][x_new_pos] > 0) { //проверка на белые фигуры в ней
				return 0;
			}
			else { 
				return 1; 
			}
		}
	}
}


//Проверка на валидность хода белым ферзём (0-нет,1-просто шаг,2-взятие фигуры)
int proverka_fers_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if (proverka_ladii_white(arr, x_pos, y_pos, x_new_pos, y_new_pos) > 0) {
		return proverka_ladii_white(arr, x_pos, y_pos, x_new_pos, y_new_pos);
	}
	else {
		return proverka_slon_white(arr, x_pos, y_pos, x_new_pos, y_new_pos);
	}
}

//Проверка на валидность хода белым королём (0-нет, 1-просто шаг, 2-взятие фигуры)
int proverka_korol_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((abs(x_new_pos - x_pos) < 2) && (abs(y_new_pos - y_pos) < 2)) {//Входит ли клетка в диапозон значений
		if (arr[y_new_pos][x_new_pos] > 6) {//Если там чёрная фигура
			return 2;
		}
		else {
			if (arr[y_new_pos][x_new_pos] == 0) {//Если там пустая клетка
				return 1;
			}
			else {//Если там белая фигура
				return 0;
			}
		}
	}
	else {
		return 0;
	}
}