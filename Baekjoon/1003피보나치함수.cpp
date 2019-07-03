#include<iostream>
#include<string.h>
using namespace std;

int dp[40] = { 0, 1 };
int cache[40];
int result[2];

int fibonacci(int n) {
	if (n < 2) {
		result[n]++;
		return n;
	}
	else if (dp[n] != -1) {
		result[cache[n]]++;
		return dp[n];
	}
	else {
		return dp[n] = fibonacci(n - 1) + fibonacci(n - 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int testcase;
	cin >> testcase;
	memset(cache, -1, sizeof(cache));
	while (testcase--) {
		int n, fibo;
		cache[0] = 0; cache[1] = 1;
		cin >> n;
		fibonacci(n);
		cout << result[0] << ' ' << result[1] << '\n';
		result[0] = 0; result[1] = 0;
	}
	return 0;
}