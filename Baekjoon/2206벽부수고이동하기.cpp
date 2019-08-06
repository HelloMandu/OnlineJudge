#include<iostream>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;

struct Node {
	int y, x, isBreak;
};

int n, m;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
string map[1001];
int isVisit[1001][1001][2];

bool isRange(int y, int x) {
	return y < n && y > -1 && x < m && x > -1;
}

int bfs() {
	queue<Node> Queue;
	Queue.push({ 0, 0, 0 });
	isVisit[0][0][0] = 1;
	while (!Queue.empty()) {
		Node front = Queue.front(); Queue.pop();
		if (front.y == n - 1 && front.x == m - 1) {
			return isVisit[front.y][front.x][front.isBreak];
		}
		for (int i = 0; i < 4; i++) {
			int nextY = front.y + dy[i];
			int nextX = front.x + dx[i];
			int isBreak = front.isBreak;
			if (!isRange(nextY, nextX) || isVisit[nextY][nextX][isBreak] != 0) {
				continue;
			}
			if (map[nextY][nextX] == '1') {
				if (isBreak == 0) {
					Queue.push({ nextY, nextX, 1 });
					isVisit[nextY][nextX][1] = isVisit[front.y][front.x][isBreak] + 1;
				}
			}
			else {
				Queue.push({ nextY, nextX, isBreak });
				isVisit[nextY][nextX][isBreak] = isVisit[front.y][front.x][isBreak] + 1;
			}
		}
	}
	return -1;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	cout << bfs();
	return 0;
}