#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n, m;
int map[501][501];
int cache[501][501];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y < n && y > -1 && x < m && x > -1;
}

int dfs(int y = 0, int x = 0) {
	if (y == n - 1 && x == m - 1) {
		return 1;
	}
	else if (cache[y][x] != -1) {
		return cache[y][x];
	}
	int result = 0;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (isRange(nextY, nextX) && map[y][x] > map[nextY][nextX]) {
			result += dfs(nextY, nextX);
		}
	}
	return cache[y][x] = result;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << dfs();
	return 0;
}