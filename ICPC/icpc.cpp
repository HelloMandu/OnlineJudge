#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>
#include<stack>
#include<queue>
using namespace std;
int n;
int a, b;
char arr1[10001];
char arr2[10001];
int cache[10001][10001];

void lcs(int start, int end) {
	for (int i = start; i <= end; i++) {
		for (int j = start; j <= end; j++) {
			if (arr1[i - 1] == arr2[j - 1]) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}
}


int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr2[i];
	}
	cin >> a >> b;
	lcs(1, a);
	lcs(a + 1, b);
	lcs(b + 1, n);
	int result = cache[a][a] + cache[b][b] + cache[n][n];
	cout << ((n - 2) <= result ? "YES" : "NO");
	return 0;
}