#include"White.h"
#include"Black.h"
#include"Game.h"

using namespace std;
//Функция преобразования одномерки в двумерку 
//Принимает одномерку, а возвращать должна двумерку
int** preobrazovanie_arr(int* arr_one) {
	int** arr = new int* [8];
	for (int i = 0; i < 8; ++i) {
		arr[i] = new int[8];
	}
	int k_i = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arr[i][j] = arr_one[k_i++];
		}
	}
	return arr;
}
int* preobrazovanie_arr_2(int** arr_dou,int* history, int true_false) {
	int arr[73];
	int k_i = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			arr[k_i++] = arr_dou[i][j];
		}
	}
	for (int i = 0; i < 7; i++) {
		arr[i + 64] = history[i];
	}
	arr[72] = true_false;
	return arr;
}

//Взятие координат из одномерки
int* get_x_y(int* arr_one) {
	int x_y[4];
	x_y[0] = (arr_one[64] + 1) % 8;
	x_y[1] = (arr_one[64] + 1) / 8;

	x_y[2] = (arr_one[65] + 1) % 8;
	x_y[3] = (arr_one[65] + 1) / 8;

	return x_y;
}

//Взятие истории
int* history(int* arr_one) {
	int history_arr[7];
	for (int i = 72; i > 65; i--) {
		history_arr[i - 66] = arr_one[i];
	}
	return history_arr;
}

//Функция проверки цвета фигуры (true - белый, false - чёрный)
bool color(int** arr, int x_pos, int y_pos){
	int value = arr[x_pos][y_pos];
	if ((arr[x_pos][y_pos] < 7) && (arr[x_pos][y_pos] != 0)) return true;
	else return false;
}

//На текущий момент эта фуекция проверяет валидность хода и, если он валиден, преобразует массив
int** proverka(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	int** new_arr = arr;
	int figur = arr[x_pos][y_pos];
	switch (figur) {
		case 1: {
			if (proverka_peshki_white) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 2: {
			if (proverka_ladii_white) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 3: {
			if (proverka_khon_white) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 4: {
			if (proverka_slon_white) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 5: {
			if (proverka_fers_white) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 6: {
			if (proverka_korol_white) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 7: {
			if (proverka_peshki_black) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 8: {
			if (proverka_ladii_black) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 9: {
			if (proverka_khon_black) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 10: {
			if (proverka_slon_black) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 11: {
			if (proverka_fers_black) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
		case 12: {
			if (proverka_korol_black) {
				new_arr = go(arr, x_pos, y_pos, x_new_pos, y_new_pos);
			}
			break;
		}
	}
	return new_arr;
}
int main() {
	int** arr	  = preobrazovanie_arr	(    );
	int coords[4] = get_x_y				(    );
	
	int		x = coords[0],		y = coords[1];
	int new_x = coords[2],	new_y = coords[3];

	int new_arr = proverka(arr,x,y,new_x,new_y);
	return new_arr;
}