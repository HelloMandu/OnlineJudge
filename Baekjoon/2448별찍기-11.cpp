#include<iostream>
using namespace std;

char arr[3072][6144];

void Star(int n, int x, int y) {
	if (n == 3) {
		arr[y][x] = '*';
		arr[y + 1][x - 1] = '*';
		arr[y + 1][x + 1] = '*';
		arr[y + 2][x - 2] = '*';
		arr[y + 2][x - 1] = '*';
		arr[y + 2][x] = '*';
		arr[y + 2][x + 1] = '*';
		arr[y + 2][x + 2] = '*';
		return;
	}
	Star(n / 2, x, y);
	Star(n / 2, x - n / 2, y + n / 2);
	Star(n / 2, x + n / 2, y + n / 2);
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n; j++)
			arr[i][j] = (j == 2 * n - 1) ? '\n' : ' ';
	Star(n, n - 1, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2 * n; j++)
			cout << arr[i][j];
	return 0;
}