#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n, k, result;
	cin >> n >> k;
	int left = 1, right = k;
	while (left <= right) {
		int mid = (left + right) / 2;
		int count = 0;
		for (int i = 1; i <= n; i++) {
			count += min(mid / i, n); // mid / i가 n을 넘어갈 수 있으므로
		}
		if (count < k) {
			left = mid + 1;
		}
		else {
			result = mid;
			right = mid - 1;
		}
	}
	cout << result;
	return 0;
}