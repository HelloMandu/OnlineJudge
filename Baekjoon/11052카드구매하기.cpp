#include<iostream>
#include<algorithm>
using namespace std;
int card[1001];
int cache[1001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> card[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cache[i] = max(cache[i], cache[i - j] + card[j]);
		}
	}
	cout << cache[n];
	return 0;
}