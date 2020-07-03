#include<iostream>
using namespace std;

bool isPrime[4000001];
int arr[4000001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 2; i * i <= 4000000; i++) {
		if (!isPrime[i]) {
			for (int j = i * i; j <= 4000000; j += i) {
				isPrime[j] = true;
			}
		}
	}
	int idx = 0;
	for (int i = 2; i <= n; i++) {
		if (!isPrime[i]) {
			arr[idx++] = i;
		}
	}
	int result = 0;
	int start = 0, end = 0;
	int sum = 0;
	while (end <= idx) {
		if (sum == n) {
			result++;
		}
		if (sum < n) {
			sum += arr[end++];
		}
		else {
			sum -= arr[start++];
		}
	}
	cout << result;
	return 0;
}