#include<iostream>
using namespace std;

int cache[1000001] = { 1, 2 };

int main() {
	int n;
	cin >> n;
	for (int i = 2; i < n; i++) {
		cache[i] = (cache[i - 1] + cache[i - 2]) % 15746;
	}
	cout << cache[n - 1];
	return 0;
}