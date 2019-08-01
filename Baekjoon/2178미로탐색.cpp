#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
using namespace std;

int n, m;
string maze[101];
int isVisit[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y < n && y > -1 && x < m && x > -1;
}

bool canVisit(int y, int x) {
	bool flag = false;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (!isRange(nextY, nextX) && !isVisit[nextY][nextX] && maze[nextY][nextX] == '1') {
			flag = true;
		}
	}
	return flag;
}

int dfs(int y = 0, int x = 0) {
	if ((y == n && x == m) && canVisit(y, x)) {
		return 1;
	}
	int result = 987654321;
	isVisit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (isRange(nextY, nextX) && !isVisit[nextY][nextX] && maze[nextY][nextX] == '1') {
			result = min(result, dfs(nextY, nextX));
		}
	}
	return result + 1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	cout << dfs();
	return 0;
}