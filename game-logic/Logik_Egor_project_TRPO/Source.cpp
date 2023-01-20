#include<iostream>
using namespace std;
//������� �������������� ��������� � �������� 
//��������� ���������, � ���������� ������ ��������
// 
//������ �������� ����������� �������� ������ ( 0 - ���, 1 - ��� �����, 2 - ��� ���� �����, 3 - ������ ������, 4 - ������ ����� �� �������)
int proverka_peshki_white(int** arr_1, int x_pos_1, int y_pos_1, int x_new_pos_1, int y_new_pos_1) {
	if ((((x_pos_1) == (x_new_pos_1)) && ((y_new_pos_1 - y_pos_1 == 1) || (y_new_pos_1 - y_pos_1 == 2)) || ((abs(x_pos_1 - x_new_pos_1) == 1) && (y_new_pos_1 - y_pos_1 == 1))) && ((arr_1[y_new_pos_1][x_new_pos_1] > 6) || (arr_1[y_new_pos_1][x_new_pos_1] == 0))) {				//�������� �� ���������� ���� (����� ����� � �� ������ ����� ������ �����/������)
		if (((x_pos_1) == (x_new_pos_1)) && ((y_new_pos_1 - y_pos_1 == 1) || (y_new_pos_1 - y_pos_1 == 2))) { //������� ��������
			if (arr_1[y_new_pos_1][x_new_pos_1] == 0) { //�������� ����������� ����� �� �������� ������
				if ((y_new_pos_1 - y_pos_1 == 2) && (y_pos_1 == 2) && (arr_1[x_pos_1][y_pos_1 + 1] == 0)) { //�������� �������� ������ (��� ��� ���� ������)
					return 2;
				}
				else {
					if (y_new_pos_1 - y_pos_1 == 1) {
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
			if (1 - arr_1[y_new_pos_1][x_new_pos_1] < -5) { // �������� �� ����������� ������������� ������ ������
				return 3;
			}
			else {
				if ((arr_1[y_new_pos_1][x_new_pos_1] == 0) && (((arr_1[y_pos_1][x_new_pos_1]) == 7) && (x_pos_1 == 5))) { // �������� �� ����������� ������ ����� �� �������
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



//������ ������� ������������ �������� ���������� ���� ����� ������ ��� ����� ����������� ���� (0-���, 1 - ������ ���, 2 - ������ ������ )
int proverka_ladii_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((x_pos == x_new_pos) || (y_pos == y_new_pos)) {//����� �� ����� ����� �����
		if (x_pos == x_new_pos) {//����� �� ����� y
			if (y_pos < y_new_pos) { //����� ����� ��� ����� 
				for (int i = y_pos + 1; i <= y_new_pos; i++) {
					if (arr[i][x_pos] == 0) { // ���� ������ ������
						if (y_new_pos == i) { // ���� ��� ��������� ������
							return 1;
						}
					}
					else {
						if ((arr[y_new_pos][x_new_pos] > 6) && (y_new_pos == i)) { //���� ��� ��������� ������ � ��� ������ ������
							return 2;
						}
						else {
							return 0;				//���� ��� �� ��������� � �� ������ ������
						}
					}
				}
			}
		}
		else {
			for (int i = y_pos - 1; i >= y_new_pos; i--) {
				if (arr[i][x_pos] == 0) { // ���� ������ ������
					if (y_new_pos == i) { // ���� ��� ��������� ������
						return 1;
					}
				}
				else {
					if ((arr[y_new_pos][x_new_pos] > 6) && (y_new_pos == i)) { //���� ��� ��������� ������ � ��� ������ ������
						return 2;
					}
					else {
						return 0;				//���� ��� �� ��������� � �� ������ ������
					}
				}
			}
		}
	}
	else {
		if (x_pos < x_new_pos) { //����� ������ ��� ����� 
			for (int j = x_pos + 1; j <= x_new_pos; j++) {
				if (arr[y_pos][j] == 0) { // ���� ������ ������
					if (x_new_pos == j) { // ���� ��� ��������� ������
						return 1;
					}
				}
				else {
					if ((arr[y_new_pos][x_new_pos] > 6) && (x_new_pos == j)) { //���� ��� ��������� ������ � ��� ������ ������
						return 2;
					}
					else {
						return 0;				//���� ��� �� ��������� � �� ������ ������
					}
				}
			}
		}
		else {
			for (int j = x_pos - 1; j >= x_new_pos; j--) {
				if (arr[y_pos][j] == 0) { // ���� ������ ������
					if (x_new_pos == j) { // ���� ��� ��������� ������
						return 1;
					}
				}
				else {
					if ((arr[y_new_pos][x_new_pos] > 6) && (x_new_pos == j)) { //���� ��� ��������� ������ � ��� ������ ������
						return 2;
					}
					else {
						return 0;				//���� ��� �� ��������� � �� ������ ������
					}
				}
			}
		}
	}
}

//�������� ���������� ���� ���� ( 0 - ���, 1 - ������ ���, 2 - ������ ������ )
int proverka_khon_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((abs(x_pos - x_new_pos) + abs(y_pos - y_new_pos) == 3) && (x_new_pos != x_pos) && (y_new_pos != y_pos)) {//�������� ������ ���� ����� ��������
		if (arr[y_new_pos][x_new_pos] == 0) {//������ �� ������
			return 1;
		}
		else {
			if (arr[y_new_pos][x_new_pos] > 6) {//׸���� �� ������ ���
				return 2;
			}
			else {
				return 0;
			}
		}
	}
}

//�������� ���������� ���� ������ ( 0 - ���, 1 - ������ ���, 2 - ������ ������ )
int proverka_slon_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	int difference = y_pos - x_pos;
	int new_difference = y_new_pos - x_new_pos;
	int sum = y_pos + x_pos;
	int new_sum = y_new_pos + x_new_pos;

	if (((difference == new_difference) || (sum == new_sum)) && ((sum % 2) == (new_sum % 2))) {//�������� �� ��������� � �������� ���������� ������
		if (y_new_pos - y_pos > 0) {// ����� �� �� �
			if (x_new_pos - x_pos > 0) {// ������ �� �� �
				for (int i = y_pos + 1, j = x_pos + 1; i < y_new_pos; i++, j++) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
			else { // ����� �� �
				for (int i = y_pos + 1, j = x_pos - 1; i < y_new_pos; i++, j--) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
		}
		else { // ���� �� �
			if (x_new_pos - x_pos > 0) { // ������
				for (int i = y_pos - 1, j = x_pos + 1; i > y_new_pos; i--, j++) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
			else { // �����
				for (int i = y_pos - 1, j = x_pos - 1; i > y_new_pos; i--, j--) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
		}
		if (arr[y_new_pos][x_new_pos] > 6) { //�������� �������� ������ �� ������ ������ � ���
			return 2;
		}
		else {
			if (arr[y_new_pos][x_new_pos] > 0) { //�������� �� ����� ������ � ���
				return 0;
			}
			else {
				return 1;
			}
		}
	}
}


//�������� �� ���������� ���� ����� ����� (0-���,1-������ ���,2-������ ������)
int proverka_fers_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if (proverka_ladii_white(arr, x_pos, y_pos, x_new_pos, y_new_pos) > 0) {
		return proverka_ladii_white(arr, x_pos, y_pos, x_new_pos, y_new_pos);
	}
	else {
		return proverka_slon_white(arr, x_pos, y_pos, x_new_pos, y_new_pos);
	}
}

//�������� �� ���������� ���� ����� ������ (0-���, 1-������ ���, 2-������ ������)
int proverka_korol_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((abs(x_new_pos - x_pos) < 2) && (abs(y_new_pos - y_pos) < 2)) {//������ �� ������ � �������� ��������
		if (arr[y_new_pos][x_new_pos] > 6) {//���� ��� ������ ������
			return 2;
		}
		else {
			if (arr[y_new_pos][x_new_pos] == 0) {//���� ��� ������ ������
				return 1;
			}
			else {//���� ��� ����� ������
				return 0;
			}
		}
	}
	else {
		return 0;
	}
}
int** go(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	arr[y_new_pos][x_new_pos] = arr[y_pos][x_pos];
	arr[y_pos][x_pos] = 0;
	return arr;
}
//������ �������� ����������� �������� ������ ( 0 - ���, 1 - ��� �����,2 - ��� ���� �����, 3 - ������ ������, 4 - ������ ����� �� �������)
int proverka_peshki_black(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if (((((x_pos) == (x_new_pos)) && ((y_new_pos - y_pos == -1) || y_new_pos - y_pos == -2)) || ((abs(x_pos - x_new_pos) == 1) && (y_new_pos - y_pos == -1))) && ((arr[y_new_pos][x_new_pos] < 7) || (arr[y_new_pos][x_new_pos] == 0))) {				//�������� �� ���������� ���� (����� ����� � �� ������ ����� ������ �����/������)
		if (((x_pos) == (x_new_pos)) && ((y_new_pos - y_pos == -1) || (y_new_pos - y_pos == -2))) { //������� ��������
			if (arr[y_new_pos][x_new_pos] == 0) { //�������� ����������� ����� �� �������� ������
				if ((y_new_pos - y_pos == -2) && (y_pos == 7) && (arr[x_pos][y_pos - 1] == 0)) { //�������� �������� ������ (��� ��� ���� ������)
					return 2;
				}
				else {
					if (y_new_pos - y_pos == -1) {
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
			if (arr[y_new_pos][x_new_pos] < 7) { // �������� �� ����������� ������������� ������ ������
				return 3;
			}
			else {
				if ((arr[y_new_pos][x_new_pos] == 0) && (((arr[y_pos][x_new_pos]) == 1) && (x_pos == 4))) { // �������� �� ����������� ������ ����� �� �������
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



//������ ������� ������������ �������� ���������� ���� ����� ������ ��� ����� ����������� ���� (0-���, 1 - ������ ���, 2 - ������ ������ )
int proverka_ladii_black(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((x_pos == x_new_pos) || (y_pos == y_new_pos)) {//����� �� ����� ����� �����
		if (x_pos == x_new_pos) {//����� �� ����� y
			if (y_pos < y_new_pos) { //����� ����� ��� ����� 
				for (int i = y_pos + 1; i <= y_new_pos; i++) {
					if (arr[i][x_pos] == 0) { // ���� ������ ������
						if (y_new_pos == i) { // ���� ��� ��������� ������
							return 1;
						}
					}
					else {
						if ((arr[y_new_pos][x_new_pos] < 7) && (y_new_pos == i)) { //���� ��� ��������� ������ � ��� ����� ������
							return 2;
						}
						else {
							return 0;       //���� ��� �� ��������� � �� ������ ������								
						}
					}
				}
			}
			else {
				for (int i = y_pos - 1; i >= y_new_pos; i--) {
					if (arr[i][x_pos] == 0) { // ���� ������ ������
						if (y_new_pos == i) { // ���� ��� ��������� ������
							return 1;
						}
					}
					else {
						if ((arr[y_new_pos][x_new_pos] < 7) && (y_new_pos == i)) { //���� ��� ��������� ������ � ��� ,����� ������
							return 2;
						}
						else {
							return 0;     //���� ��� �� ��������� � �� ������ ������

						}
					}
				}
			}
		}
		else {
			if (x_pos < x_new_pos) { //����� ������ ��� ����� 
				for (int j = x_pos + 1; j <= x_new_pos; j++) {
					if (arr[y_pos][j] == 0) { // ���� ������ ������
						if (x_new_pos == j) { // ���� ��� ��������� ������
							return 1;
						}
					}
					else {
						if ((arr[y_new_pos][x_new_pos] < 7) && (x_new_pos == j)) { //���� ��� ��������� ������ � ��� ����� ������
							return 2;
						}
						else {
							return 0;
						}
					}
				}
			}
			else {
				for (int j = x_pos - 1; j >= x_new_pos; j--) {
					if (arr[y_pos][j] == 0) { // ���� ������ ������
						if (x_new_pos == j) { // ���� ��� ��������� ������
							return 1;
						}
					}
					else {
						if ((arr[y_new_pos][x_new_pos] < 7) && (x_new_pos == j)) { //���� ��� ��������� ������ � ��� ����� ������
							return 2;
						}
						else {
							return 0;//���� ��� �� ��������� � �� ������ ������
						}
					}
				}
			}

		}

	}
}




//�������� ���������� ���� ���� ( 0 - ���, 1 - ������ ���, 2 - ������ ������ )
int proverka_khon_black(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((abs(x_pos - x_new_pos) + abs(y_pos - y_new_pos) == 3) && (x_new_pos != x_pos) && (y_new_pos != y_pos)) {//�������� ������ ���� ����� ��������
		if (arr[y_new_pos][x_new_pos] == 0) {//������ �� ������
			return 1;
		}
		else {
			if (arr[y_new_pos][x_new_pos] < 7) {//����� �� ������ ���
				return 2;
			}
			else {
				return 0;
			}
		}
	}
}

//�������� ���������� ���� ������ ( 0 - ���, 1 - ������ ���, 2 - ������ ������ )
int proverka_slon_black(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	int difference = y_pos - x_pos;
	int new_difference = y_new_pos - x_new_pos;
	int sum = y_pos + x_pos;
	int new_sum = y_new_pos + x_new_pos;

	if (((difference == new_difference) || (sum == new_sum)) && ((sum % 2) == (new_sum % 2))) {//�������� �� ��������� � �������� ���������� ������
		if (y_new_pos - y_pos > 0) {// ����� �� �� �
			if (x_new_pos - x_pos > 0) {// ������ �� �� �
				for (int i = y_pos + 1, j = x_pos + 1; i < y_new_pos; i++, j++) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
			else { // ����� �� �
				for (int i = y_pos + 1, j = x_pos - 1; i < y_new_pos; i++, j--) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
		}
		else { // ���� �� �
			if (x_new_pos - x_pos > 0) { // ������
				for (int i = y_pos - 1, j = x_pos + 1; i > y_new_pos; i--, j++) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
			else { // �����
				for (int i = y_pos - 1, j = x_pos - 1; i > y_new_pos; i--, j--) {
					if (arr[i][j] != 0) {
						return 0;
					}
				}
			}
		}
		if (arr[y_new_pos][x_new_pos] > 6) { //�������� �������� ������ �� ������ ������ � ���
			return 0;
		}
		else {
			if (arr[y_new_pos][x_new_pos] == 0) { //�������� �� ����� ������ � ���
				return 1;
			}
			else {
				return 2;
			}
		}
	}
}

//�������� �� ���������� ���� ������ ����� (0-���,1-������ ���,2-������ ������)
int proverka_fers_black(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if (proverka_ladii_black(arr, x_pos, y_pos, x_new_pos, y_new_pos) > 0) {
		return proverka_ladii_black(arr, x_pos, y_pos, x_new_pos, y_new_pos);
	}
	else {
		return proverka_slon_black(arr, x_pos, y_pos, x_new_pos, y_new_pos);
	}
}

//�������� �� ���������� ���� ������ ������ (0-���, 1-������ ���, 2-������ ������)
int proverka_korol_black(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((abs(x_new_pos - x_pos) < 2) && (abs(y_new_pos - y_pos) < 2)) {//������ �� ������ � �������� ��������
		if (arr[y_new_pos][x_new_pos] == 0) {//���� ��� ������ ������
			return 1;
		}
		else {
			if (arr[y_new_pos][x_new_pos] < 7) {//���� ��� ����� ������
				return 2;
			}
			else {//���� ��� ������ ������
				return 0;
			}
		}
	}
	else {
		return 0;
	}
}
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

//������ ��������� �� ���������


//������ �������
int* history(int* arr_one) {
	int history_arr[7];
	for (int i = 72; i > 65; i--) {
		history_arr[i - 66] = arr_one[i];
	}
	return history_arr;
}

//������� �������� ����� ������ (true - �����, false - ������)
bool color(int** arr, int x_pos, int y_pos){
	int value = arr[x_pos][y_pos];
	if ((arr[x_pos][y_pos] < 7) && (arr[x_pos][y_pos] != 0)) return true;
	else return false;
}

//�� ������� ������ ��� ������� ��������� ���������� ���� �, ���� �� �������, ����������� ������
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
	int arr_test[73] = { 2,3,4,5,6,4,3,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0, 7, 7, 7, 7, 7, 7, 7, 7, 8, 9, 10, 11, 12, 10, 9, 8, 12, 38, 0,0,0,0,0,0,0,0 };
	int** arr	  = preobrazovanie_arr	(arr_test);	
	int		x	  = arr_test[64]%8,		y = arr_test[64] / 8;
	int new_x	  = arr_test[65] % 8,	new_y = arr_test[65] / 8;

	int** new_arr	  = proverka(arr,x,y,new_x,new_y);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << arr[i][j] <<" ";
		}
		cout << endl;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << new_arr[i][j] << " ";
		}
		cout << endl;
	}
}