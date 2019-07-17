#include<iostream>
#include<algorithm>
using namespace std;
char board[52][52];
int change[52][52];
int n, m;

int minPaint() {
	int result = 987654321;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			int count = 0;
			for (int k = 0; k < 8; k++) {
				for (int l = 0; l < 8; l++) {
					count += change[i + k][j + l];
				}
			}
			result = min(result, min(count, 64 - count)); // 64 - count = B먼저인경우
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
			//W먼저인경우
			if ((i + j) % 2 == 0 && board[i][j] != 'W') {
				change[i][j]++;
			}
			else if ((i + j) % 2 == 1 && board[i][j] != 'B') {
				change[i][j]++;
			}
		}
	}
	cout << minPaint();
	return 0;
}