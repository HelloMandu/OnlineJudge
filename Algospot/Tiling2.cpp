/*동적프로그래밍을 이용한 타일링문제*/
#include<iostream>
using namespace std;

int dp[1001];
/*int Tiling2(int n) { // recursion
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;
	else if (dp[n])
		return dp[n];
	else
		return dp[n] = (Tiling2(n - 1) + Tiling2(n - 2) * 2) % 10007;
}*/

int Tiling2(int n) { // bottom-up
	dp[1] = 1; dp[2] = 2;
	for (int i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2])  % 1000000007;
	return dp[n];
}

int main() {
	int n;
	cin >> n;
	cout << Tiling2(n);
	return 0;
}