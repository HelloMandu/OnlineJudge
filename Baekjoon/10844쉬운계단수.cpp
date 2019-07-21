#include<iostream>
using namespace std;

long long cache[101][10] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0) {
				cache[i][j] += cache[i - 1][1];
			}
			else if (j == 9) {
				cache[i][j] += cache[i - 1][8];
			}
			else {
				cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % 1000000000;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum = (sum + cache[n - 1][i]) % 1000000000;
	}
	cout << sum;
	return 0;
}