#include<iostream>
#include<algorithm>
using namespace std;

int n;
int arr[2][100001];
int cache[2][100001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		for (int i = 0; i < 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> arr[i][j];
			}
		}
		cache[0][1] = arr[0][1];
		cache[1][1] = arr[1][1];
		for (int i = 2; i <= n; i++) {
			cache[0][i] = max({ cache[1][i - 1], cache[1][i - 2] }) + arr[0][i];
			cache[1][i] = max({ cache[0][i - 1], cache[0][i - 2] }) + arr[1][i];
		}
		cout << max(cache[0][n], cache[1][n]) << '\n';
	}

	return 0;
}