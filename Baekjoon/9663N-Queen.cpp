#include<iostream>
#include<cmath>
using namespace std;

int arr[15];
int n;
int cnt = 0;

bool promising(int row) {
	for (int i = 0; i < row; i++) {
		/*직선이나 대각선에 있는지 확인*/
		if (arr[i] == arr[row] || abs(i - row) == abs(arr[i] - arr[row])) {
			return false;
		}
	}
	return true;
}

void NQueen(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int col = 0; col < n; col++) {
		arr[row] = col;
		if (promising(row)) {
			NQueen(row + 1);
		}
	}
}

int main() {
	cin >> n;
	NQueen(0);
	cout << cnt;
	return 0;
}