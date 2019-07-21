#include<iostream>
#include<algorithm>
using namespace std;

int juice[10001];
int cache[10001];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> juice[i];
	}
	cache[1] = juice[1];
	cache[2] = juice[1] + juice[2];
	for (int i = 3; i <= n; i++) {
		cache[i] = max(max(cache[i - 1], juice[i] + cache[i - 2]), juice[i] + juice[i - 1] + cache[i - 3]);
	}
	cout << cache[n];
	return 0;
}