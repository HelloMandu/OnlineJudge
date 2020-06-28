#include<iostream>
#include<cstring>
using namespace std;

int cache[31][31];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(cache, 0, sizeof(cache));
		int n, m;
		cin >> n >> m;
		for (int i = 1; i <= m; i++) {
			cache[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = i - 1; k < j; k++) {
					cache[i][j] += cache[i - 1][k];
				}
			}
		}
		cout << cache[n][m] << '\n';
	}
	return 0;
}