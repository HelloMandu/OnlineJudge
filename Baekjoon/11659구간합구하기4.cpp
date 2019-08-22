#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int sum[100001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		sum[i] = sum[i - 1] + num;
	}
	for (int i = 0; i < m; i++) {
		int left, right;
		cin >> left >> right;
		cout << sum[right] - sum[left - 1] << '\n';
	}
	return 0;
}