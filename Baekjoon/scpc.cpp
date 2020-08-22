#include<iostream>
#include<algorithm>
#include<cstring>
#define WIN 1
#define LOSE 0
using namespace std;
#pragma warning(disable:4996)

int n, k;
int cardA[3001], cardB[3001];
int sum[3001][3001];

int cache[3001][3001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	freopen("input.txt", "r", stdin);
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		memset(cache, LOSE, sizeof(cache));
		memset(sum, 0, sizeof(sum));
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> cardA[i] >> cardB[i];
			sum[i][0] = sum[i - 1][0] + cardA[i];
			sum[0][i] = sum[0][i - 1] + cardB[i];
			sum[i - 1][i] = sum[i - 1][i - 1] + cardA[i];
			sum[i][i - 1] = sum[i - 1][i - 1] + cardB[i];
			sum[i][i] = sum[i - 1][i - 1] + cardA[i] + cardB[i];
		}
		int win = 1, lose = 0;
		cache[0][0] = WIN;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (cache[i][j] == LOSE) {

				}
			}
		}
		cout << "Case #" << t << '\n';
		cout << win << ' ' << lose << '\n';
	}
	return 0;
}