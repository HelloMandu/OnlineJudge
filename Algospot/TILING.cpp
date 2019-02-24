#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

long long cache[100000001];
long long Tiling(int n) {
	if (n <= 1) {
		return 1;
	}
	else if (n == 2) {
		return 3;
	}
	else if (cache[n]) {
		return cache[n];
	}
	return cache[n] = Tiling(n - 1) * 3 + Tiling(n - 2);
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n;
		cin >> n;
		cout << Tiling(n) << '\n';
	}
	return 0;
}