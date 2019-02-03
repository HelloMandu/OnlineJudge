#include<iostream>
using namespace std;

long long dp[1001][1001];
long long BinomialCoefficient(int n, int k) {
	if (n == k || k == 0)
		return 1;
	else if (dp[n][k])
		return dp[n][k];
	else
		return dp[n][k] = (BinomialCoefficient(n - 1, k - 1) + BinomialCoefficient(n - 1, k)) % 1000000007;
}

int main() {
	int n, k;
	cin >> n >> k;
	cout << BinomialCoefficient(n, k);
	return 0;
}