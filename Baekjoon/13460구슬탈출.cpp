#include<iostream>
#include<queue>
using namespace std;

struct Ball {
	int ry, rx, by, bx, cnt = 0;
};

char map[11][11];
pair<int, int>  hole;
bool visit[11][11][11][11];
int rx, ry, bx, by;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void move(int &y, int &x, int dir) {
	while (map[y][x] != 'O') {
		y += dy[dir];
		x += dx[dir];
		if (map[y][x] == '#') {
			y -= dy[dir];
			x -= dx[dir];
			return;
		}
	}
}

int findHole() {
	queue<Ball> Queue;
	Queue.push({ ry, rx, by, bx, 0 });
	visit[ry][rx][by][bx] = true;
	while (!Queue.empty()) {
		Ball cur = Queue.front(); Queue.pop();
		if (cur.cnt > 10) {
			return -1;
		}
		else if (map[cur.ry][cur.rx] == 'O') {
			return cur.cnt;
		}
		for (int i = 0; i < 4; i++) {
			int ry = cur.ry, rx = cur.rx, by = cur.by, bx = cur.bx;
			move(ry, rx, i);
			move(by, bx, i);
			if (map[by][bx] != 'O') {
				if (ry == by && rx == bx) {
					switch (i) {
					case 0:
						if (cur.ry < cur.by) { by++; }
						else { ry++; }
						break;
					case 1:
						if (cur.rx < cur.bx) { rx--; }
						else { bx--; }
						break;
					case 2:
						if (cur.ry < cur.by) { ry--; }
						else { by--; }
						break;
					case 3:
						if (cur.rx < cur.bx) { bx++; }
						else { rx++; }
						break;
					}
				}
				if (!visit[ry][rx][by][bx]) {
					Queue.push({ ry, rx, by, bx, cur.cnt + 1 });
					visit[ry][rx][by][bx] = true;
				}
			}
		}
	}
	return -1;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'R') {
				ry = i, rx = j;
				map[i][j] = '.';
			}
			else if (map[i][j] == 'B') {
				by = i, bx = j;
				map[i][j] = '.';
			}
		}
	}
	cout << findHole();
	return 0;
}