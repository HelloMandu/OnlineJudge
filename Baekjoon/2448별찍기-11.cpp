#include<iostream>
#define fastio() ios_base::sync_base_studio(false), cin.tie(null), cout.tie(null);
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