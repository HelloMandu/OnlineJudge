#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char arr[10001][10001];

void setStar(int x, int y, int n) {
	if (n == 1) {
		arr[x][y] = '*';
		return;
	}
	int div = n / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (i != 1 || j != 1) {
				setStar(x + (i * div), y + (j * div), div);
			}
		}
	}
}

int main() {
	fastIO();
	int n;
	cin >> n;
	memset(arr, ' ', sizeof(arr));
	setStar(0, 0, n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j];
		}
		cout << '\n';
	}
	return 0;
}