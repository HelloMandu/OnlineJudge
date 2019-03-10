/*동적프로그래밍을 이용한 타일링문제*/
#include<iostream>
#include<cstring>
#define MOD 1000000007
using namespace std;

int cache[101];

int Tiling(int n) { // recursion
	/*기저사례*/
	if (n <= 1) {
		return 1;
	}
	int &ret = cache[n];
	if (ret != -1) {
		return ret;
	}
	return ret = (Tiling(n - 1) + Tiling(n - 2)) % MOD;
}

int asymTiling(int n) {
	/*홀수 일때*/
	if (n % 2 == 1) {
		return (Tiling(n) - Tiling(n / 2) + MOD) % MOD;
	}
	/*짝수 일때*/
	int ret = Tiling(n);
	ret = (ret - Tiling(n / 2) + MOD) % MOD;
	ret = (ret - Tiling(n / 2 - 1) + MOD) % MOD;
	return ret;
}

int main() {
	int testcase;
	cin >> testcase;
	memset(cache, -1, sizeof(cache));
	while (testcase--) {
		int n;
		cin >> n;
		cout << asymTiling(n) << '\n';
	}
	return 0;
}