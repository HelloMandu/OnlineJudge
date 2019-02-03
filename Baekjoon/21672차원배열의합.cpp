#include<iostream>
using namespace std;

int dp[301][301];
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			cin >> temp;
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + temp;
		}
	}
	int k;
	cin >> k;
	while (k--) {
		int i, j, x, y;
		cin >> i >> j >> x >> y;
		cout << dp[x][y] - dp[x][j - 1] - dp[i - 1][y] + dp[i - 1][j - 1] << '\n';
	}
	return 0;
}