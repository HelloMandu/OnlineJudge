#include<iostream>
using namespace std;

int arr[21];
long long fact[21];
bool flag[21];

long long factorial(int n) {
	if (n == 1) {
		return fact[n] = n;
	}
	return fact[n] = n * factorial(n - 1);
}

int main() {
	int n, type;
	cin >> n >> type;
	factorial(n);
	if (type == 1) {
		long long k, idx = 0;
		cin >> k;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!flag[j]) {
					if (k > 1&& fact[n - i] < k) {
						k -= fact[n - i];
					}
					else {
						flag[j] = true;
						arr[i - 1] = j;
						break;
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {
			cout << arr[i] << ' ';
		}
	}
	else {
		long long result = 0;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i < n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!flag[j]) {
					if (j == arr[i]) {
						flag[j] = true;
						break;
					}
					else {
						result += fact[n - i];
					}
				}

			}
		}
		cout << result + 1;
	}
	return 0;
}