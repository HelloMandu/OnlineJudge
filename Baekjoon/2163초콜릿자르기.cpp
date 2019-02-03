#include<iostream>
using namespace std;

/*int dp[301];
int Chocolate(int n, int m) {
	dp[1] = n - 1;
	for (int i = 2; i <= m; i++) {
		dp[i] = dp[i - 1] + n;
	}
	return dp[m];
}*/

int main() {
	int n, m;
	cin >> n >> m;
	cout << n * m - 1;
	return 0;
}