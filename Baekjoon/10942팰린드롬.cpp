#include<iostream>
using namespace std;

int dp[2001][2001];
int arr[2001];

void isPalindrome(int n) {
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	for (int i = 1; i <= n - 1; i++) {
		if (arr[i] == arr[i + 1]) {
			dp[i][i + 1] = 1;
		}
	}
	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1]) {
				dp[j][j + i] = 1;
			}
		}
	}
}

int main() {
	int n, m, start, end;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	isPalindrome(n);
	scanf("%d", &m);

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &start, &end);
		printf("%d\n", dp[start][end]);
	}
	return 0;
}