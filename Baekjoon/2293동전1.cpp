#include<iostream>
#include<algorithm>
using namespace std;
int n, k;
int coin[10001];
int cache[10001];

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cache[0] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= k; j++) {
			if (j - coin[i] >= 0) {
				cache[j] += cache[j - coin[i]];
			}
		}
	}
	cout << cache[k];
	return 0;
}