#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

int n, m;
string maze[101];
int isVisit[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };


bool isRange(int y, int x) {
	return y < n && y > -1 && x < m && x > -1;
}

int bfs() {
	int y = 0, x = 0;
	isVisit[y][x] = 1;
	queue<pair<int, int> > Queue;
	Queue.push({ y, x });
	while (!Queue.empty()) {
		y = Queue.front().first; x = Queue.front().second;
		if (y == n - 1 && x == m - 1) {
			return isVisit[n - 1][m - 1];
		}
		Queue.pop();
		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (isRange(nextY, nextX) && !isVisit[nextY][nextX] && maze[nextY][nextX] == '1') {
				isVisit[nextY][nextX] += isVisit[y][x] + 1;
				Queue.push({ nextY, nextX });
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> maze[i];
	}
	cout << bfs();
	return 0;
}