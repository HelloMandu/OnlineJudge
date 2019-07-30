#include<iostream>
#include<algorithm>
#define INFINITY 987654321
using namespace std;
int n;
int arr[501];
int sum[501];
int cache[501][501];

int unionFile(int start, int end) {
	if (cache[start][end] != INFINITY) {
		return cache[start][end];
	}
	else if (start == end) {
		return cache[start][end] = 0;
	}
	else if (start + 1 == end) {
		return cache[start][end] = arr[start] + arr[end];
	}
	for (int mid = start; mid < end; mid++) {
		cache[start][end] = min(cache[start][end], unionFile(start, mid) + unionFile(mid + 1, end));
	}
	return cache[start][end] += sum[end] - sum[start - 1];
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		fill(&cache[0][0], &cache[n][n] + 1, INFINITY);
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			sum[i] = arr[i] + sum[i - 1];
		}
		cout << unionFile(1, n) << '\n';
	}

	return 0;
}