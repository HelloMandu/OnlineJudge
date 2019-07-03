#include<iostream>
using namespace std;

int cache[301][301];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			cin >> temp;
			cache[i][j] = cache[i - 1][j] + cache[i][j - 1] - cache[i - 1][j - 1] + temp;
		}
	}
	int k;
	cin >> k;
	while (k--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << cache[x][y] - cache[x][j - 1] - cache[i - 1][y] + cache[i - 1][j - 1] << '\n';
	}
	return 0;
}