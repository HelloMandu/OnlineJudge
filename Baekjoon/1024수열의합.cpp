#include<iostream>
#include<climits>
using namespace std;

long long n, l;

long long sum(long long n) {
	return 1LL * n * (n + 1) / 2;
}

bool find(long long len) {
	long long left = 0, right = INT_MAX;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long x = sum(mid + len - 1) - sum(mid - 1);
		if (x == n) {
			for (long long i = mid; i < mid + len; i++) {
				cout << i << ' ';
			}
			return true;
		}
		if (x > n) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> l;
	bool isFind = false;
	for (int i = l; i <= 100; i++) {
		isFind = find(i);
		if (isFind) {
			break;
		}
	}
	if (!isFind) {
		cout << -1;
	}
	return 0;
}