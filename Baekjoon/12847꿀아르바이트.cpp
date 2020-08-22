#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
long long arr[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		arr[i + 1] += arr[i];
	}
	long long result = arr[m - 1];
	for (int i = 0; i < n - m + 1; i++) {
		result = max(result, arr[i + m] - arr[i]);
	}
	cout << result;
	return 0;
}