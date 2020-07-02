#include<iostream>
#define fastio() ios_base::sync_base_stdio(false), cin.tie(null), cout.tie(null);
using namespace std;

char arr[3072][6144];

void star(int n, int x, int y) {
	if (n == 3) {
		arr[y][x] = 
		arr[y + 1][x - 1] = 
		arr[y + 1][x + 1] = 
		arr[y + 2][x - 2] = 
		arr[y + 2][x - 1] = 
		arr[y + 2][x] = 
		arr[y + 2][x + 1] = 
		arr[y + 2][x + 2] = '*';
		return;
	}
	star(n / 2, x, y);
	star(n / 2, x - n / 2, y + n / 2);
	star(n / 2, x + n / 2, y + n / 2);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n; j++)
			arr[i][j] = (j == 2 * n - 1) ? '\n' : ' ';
	star(n, n - 1, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n; j++)
			cout << arr[i][j];
	return 0;
}
//#include<iostream>
//using namespace std;
//
//char arr[10001][10001];
//int n;
//
//void star(int row, int start, int end) {
//	if (row == n * 3) {
//		return;
//	}
//	for (int i = start; i < end; i += 6) {
//		arr[row][i] = '*';
//		arr[row][i + 1] = '*';
//		arr[row][i + 2] = '*';
//		arr[row][i + 3] = '*';
//		arr[row][i + 4] = '*';
//		arr[row + 1][i + 1] = '*';
//		arr[row + 1][i + 3] = '*';
//		arr[row + 2][i + 2] = '*';
//	}
//	star(row + 3, start + 3, end - 3);
//}
//
//int main() {
//	cin >> n;
//	for (int i = 0; i < n * 3; i++) {
//		for (int j = 0; j < 6 * n + 1; j++) {
//			arr[i][j] = ' ';
//		}
//	}
//	star(0, 0, 6 * n);
//	for (int i = n * 3 - 1; i >= 0; i--) {
//		for (int j = 0; j < 6 * n; j++) {
//			cout << arr[i][j];
//		}
//		cout << '\n';
//	}
//	return 0;
//}
