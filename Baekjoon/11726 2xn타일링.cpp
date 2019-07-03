#include<iostream>
using namespace std;

int cache[1001];
/*int Tiling(int n) { // recursion
	if (n < 3)
		return dp[n] = n;
	else if (dp[n] != 0)
		return dp[n];
	else 
		return dp[n] = (Tiling(n - 1) + Tiling(n - 2)) % 10007;
}*/

int Tiling(int n) { // bottom-up
	cache[1] = 1; cache[2] = 2;
	for (int i = 3; i <= n; i++)
		cache[i] = (cache[i - 1] + cache[i - 2]) % 10007;
	return cache[n];
}

int main() {
	int n;
	cin >> n;
	cout << Tiling(n);
	return 0;
}