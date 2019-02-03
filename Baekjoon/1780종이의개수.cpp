#include<iostream>
using namespace std;
int arr[5000][5000];
int result[3];

bool CheckPaper(int row, int col, int n) {
	for (int i = row; i < row + n; i++) {
		for (int j = col; j < col + n; j++) {
			if (arr[row][col] != arr[i][j])
				return false;
		}
	}
	return true;
}

void GetResult(int row, int col, int n) {
	/*종이의 사이즈가 1일때*/
	if (n == 1) {
		result[arr[row][col] + 1]++;
		return;
	}
	/* 종이에 모드 값이 같을때*/
	else if (CheckPaper(row, col, n)) { 
		result[arr[row][col] + 1]++;
		return;
	}
	else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				GetResult(row + (n / 3) * i, col + (n / 3) * j, n / 3);
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> arr[i][j];
	GetResult(0, 0, n);
	for (int i = 0; i < 3; i++)
		cout << result[i] << '\n';
	return 0;
}