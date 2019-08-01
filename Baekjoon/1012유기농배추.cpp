#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
int m, n, k; // 가로, 세로, 배추갯수
int field[2501][2501];
int isVisit[2501][2501];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y < m && y > -1 && x < n && x > -1;
}

void dfs(int y, int x) {
	isVisit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (isRange(nextY, nextX) && !isVisit[nextY][nextX] && field[nextY][nextX] == 1) {
			dfs(nextY, nextX);
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> m >> n >> k;
		while (k--) {
			int y, x;
			cin >> y >> x;
			field[y][x] = 1;
		}
		int result = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!isVisit[i][j] && field[i][j] == 1) {
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << '\n';
		memset(field, 0, sizeof(field));
		memset(isVisit, false, sizeof(isVisit));

	}
	return 0;
}