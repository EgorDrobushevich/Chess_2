#include<iostream>


//������ �������� ����������� �������� ������ ( 0 - ���, 1 - ��� �����, 2 - ��� ���� �����, 3 - ������ ������, 4 - ������ ����� �� �������)
int proverka_peshki_white(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	if ((((x_pos) == (x_new_pos)) && ((y_new_pos - y_pos == 1) || (y_new_pos - y_pos == 2)) || ((abs(x_pos - x_new_pos) == 1) && (y_new_pos - y_pos == 1))) && ((arr[y_new_pos][x_new_pos] > 6) || (arr[y_new_pos][x_new_pos] == 0))) {				//�������� �� ���������� ���� (����� ����� � �� ������ ����� ������ �����/������)
		if (((x_pos) == (x_new_pos)) && ((y_new_pos - y_pos == 1) || (y_new_pos - y_pos == 2))) { //������� ��������
			if (arr[y_new_pos][x_new_pos] == 0) { //�������� ����������� ����� �� �������� ������
				if ((y_new_pos - y_pos == 2) && (y_pos == 2) && (arr[x_pos][y_pos + 1] == 0)) { //�������� �������� ������ (��� ��� ���� ������)
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
			if (1 - arr[y_new_pos][x_new_pos] < -5) { // �������� �� ����������� ������������� ������ ������
				return 3;
			}
			else {
				if ((arr[y_new_pos][x_new_pos] == 0) && (((arr[y_pos][x_new_pos]) == 7) && (x_pos == 5))) { // �������� �� ����������� ������ ����� �� �������
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

	if (((difference == new_difference)||(sum==new_sum))&&((sum%2)==(new_sum%2))) {//�������� �� ��������� � �������� ���������� ������
		if (y_new_pos - y_pos>0) {// ����� �� �� �
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