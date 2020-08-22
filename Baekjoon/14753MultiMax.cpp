#include<iostream>
#include<algorithm>
using namespace std;

long long arr[10001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int a = max(arr[n - 1] * arr[n - 2], arr[n - 1] * arr[n - 2] * arr[n - 3]);
	int b = max(arr[0] * arr[1], arr[0] * arr[1] * arr[n - 1]);
	cout << max(a, b);
	return 0;
}