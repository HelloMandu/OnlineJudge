#include<iostream>
using namespace std;

bool arr[1000001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	long long n, m;
	cin >> n >> m;
	for (long long i = 2; i * i <= m; i++) {
		long long square = i * i;
		long long quotient = n / square;
		if (n % square != 0) {
			quotient++;
		}
		while (quotient * square <= m) {
			arr[quotient*square - n] = true;
			quotient++;
		}
	}

	long long cnt = m - n + 1;
	for (int i = 0; i < m - n + 1; i++) {
		if (arr[i]) {
			cnt--;
		}
	}
	cout << cnt;
	return 0;
}