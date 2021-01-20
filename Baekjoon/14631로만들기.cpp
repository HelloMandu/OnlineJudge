#include<iostream>
using namespace std;

int cache[1000001];

int main() {
	int n;
	cin >> n;
	cache[1] = 0; cache[2] = 1; cache[3] = 1;
	for (int i = 4; i <= n; i++) {
		cache[i] = cache[i - 1] + 1;
		if (i % 3 == 0) {
			cache[i] = min(cache[i], cache[i / 3] + 1);
		}
		if (i % 2 == 0) {
			cache[i] = min(cache[i], cache[i / 2] + 1);
		}
	}
	cout << cache[n];
	return 0;
}