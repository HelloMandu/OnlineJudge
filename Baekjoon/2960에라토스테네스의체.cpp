#include<iostream>
using namespace std;

bool prime[1001];

int main() {
	int n, k, cnt = 0;
	cin >> n >> k;
	for (int i = 2; i * i <= 100001; i++) {
		if (!prime[i]) {
			prime[i] = true;
			cnt++;
			if (cnt == k) {
				cout << i;
				return 0;
			}
			for (int j = i * i; j <= n; j += i) {
				if (!prime[j]) {
					prime[j] = true;
					cnt++;
					if (cnt == k) {
						cout << j;
						return 0;
					}
				}
			}
		}
	}
	return 0;
}