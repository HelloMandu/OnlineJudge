#include<iostream>
#define MAX 16
using namespace std;

int grid[MAX][MAX];

int computeRoute(int n, int m) {
	if (grid[n][m]) {
		return grid[n][m];
	}
	grid[1][1] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i != 1 || j != 1) {
				grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
			}
		}
	}
	return grid[n][m];
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	if (k == 0) {
		cout << computeRoute(n, m);
	}
	else {
		int x, y;
		if (k % m == 0) {
			x = k / m, y = m;
		}
		else {
			x = k / m + 1, y = k % m;
		}
		cout << computeRoute(n - x + 1, m - y + 1) * computeRoute(x, y);
	}
	cout << '\n';
	return 0;
}