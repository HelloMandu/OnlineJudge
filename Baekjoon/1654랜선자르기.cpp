#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;

long long n, k;
long long lan[10001];
long long start = 0, finish = LLONG_MAX;
long long result = 0;
int main() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		cin >> lan[i];
	}
	while (start <= finish) {
		long long mid = (start + finish) / 2;
		long long sum = 0;
		for (int i = 0; i < k; i++) {
			sum += lan[i] / mid;
		}
		if (sum < n) {
			finish = mid - 1;
		}
		else {
			start = mid + 1;
			result = max(result, mid);
		}
	}
	cout << result;
	return 0;
}