
int** go(int** arr, int x_pos, int y_pos, int x_new_pos, int y_new_pos) {
	arr[y_new_pos][x_new_pos] = arr[y_pos][x_pos];
	arr[y_pos][x_pos] = 0;
	return arr;
}
/*
int get_x_korol(int** arr, bool color){
	int value_color = 0;
	if (color) {
		value_color = 6;
	}
	else {
		value_color = 12;
	}
	for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 8; j++) {
				if (arr[i][j] == value_color) {
					return j;
				}
			}
		}
}

int get_y_korol(int** arr, bool color) {
	int value_color = 0;
	if (color) {
		value_color = 6;
	}
	else {
		value_color = 12;
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (arr[i][j] == value_color) {
				return i;
			}
		}
	}
}

/*int shah(int** arr, bool color) {
	int x_korol = get_x_korol(arr, color);
	int y_korol = get_y_korol(arr, color);

}*/

