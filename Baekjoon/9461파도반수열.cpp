#include<iostream>
using namespace std;

long long cache[101] = { 1, 1, 1, 2, 2 };

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 5; i < 101; i++) {
		cache[i] = cache[i - 1] + cache[i - 5];
	}
	while (testcase--) {
		int n;
		cin >> n;
		cout << cache[n - 1] << '\n';
	}
	return 0;
}