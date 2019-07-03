#include<iostream>
using namespace std;

int cache[1001];
/*int Tiling2(int n) { // recursion
	if (n == 1)
		return 1;
	else if (n == 2)
		return 3;
	else if (dp[n])
		return dp[n];
	else
		return dp[n] = (Tiling2(n - 1) + Tiling2(n - 2) * 2) % 10007;
}*/

int Tiling2(int n) { // bottom-up
	cache[1] = 1; cache[2] = 3;
	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 1] + cache[i - 2] * 2) % 10007;
	return cache[n];
}

int main() {
	int n;
	cin >> n;
	cout << Tiling2(n);
	return 0;
}