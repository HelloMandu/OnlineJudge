#include<iostream>
#include<string>
using namespace std;

int sudoku[9][9];

bool row[10][10], col[10][10], matrix[9][10];

bool canSelect(int cnt, int n) {
	int y = cnt / 9, x = cnt % 9;
	return !row[y][n] && !col[x][n] && !matrix[(y / 3) * 3 + x / 3][n];
}

bool makeResult(int cnt) {
	if (cnt == 81) {

		return true;
	}
	int y = cnt / 9, x = cnt % 9;
	if (sudoku[y][x] != 0) {
		return makeResult(cnt + 1);
	}
	for (int i = 1; i <= 9; i++) {
		if (canSelect(cnt, i)) {
			sudoku[y][x] = i;
			row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = true;
			if (makeResult(cnt + 1)) { return true; }
			row[y][i] = col[x][i] = matrix[(y / 3) * 3 + x / 3][i] = false;
			sudoku[y][x] = 0;
		}
	}
	return false;
}

int main() {
	for (int i = 0; i < 9; i++) {
		string a; cin >> a;
		for (int j = 0; j < 9; j++) {
			sudoku[i][j] = a[j] - '0';
			int n = sudoku[i][j];
			row[i][n] = col[j][n] = matrix[(i / 3) * 3 + j / 3][n] = true;
		}
	}
	if (makeResult(0)) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << sudoku[i][j];
			}
			cout << '\n';
		}
	}
	return 0;
}
