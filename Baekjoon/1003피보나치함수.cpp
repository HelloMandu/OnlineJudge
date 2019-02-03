#include<iostream>
#include<algorithm>
using namespace std;

//int dp[40] = {0, 1};
int result[2];
/*int Fibonacci(int n) {
	if (n < 2)
		return dp[n];
	else if (dp[n])
		return dp[n];
	else
		return dp[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}

int Fibonacci(int n) {
	if (n == 0) {
		result[0]++;
		return 0;
	}
	else if (n == 1) {
		result[1]++;
		return 1;
	}
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}*/

void Fibonacci(int n) {
	if (n == 0) {
		result[0]++;
		return;
	}
	else if (n == 1) {
		result[1]++;
		return;
	}
	result[0]++; result[1]++;
	for (int i = 2; i < n; i++) {
		int temp = result[1];
		result[1] += result[0];
		result[0] = temp;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, fibo;
		cin >> n;
		/*if (n == 0)
			cout << "1 0\n";
		else if (n == 1)
			cout << "0 1\n";
		else {
			Fibonacci(n);
			cout << dp[n - 1] << ' ' << dp[n] << '\n';
		}*/
		Fibonacci(n);
		cout << result[0] << ' ' << result[1] << '\n';
		result[0] = 0; result[1] = 0;
	}
	return 0;
}