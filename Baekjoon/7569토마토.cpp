#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

struct Riped {
	int h, y, x;
};

int m, n, h; // 가로, 세로, 높이
int box[101][101][101];
int dh[6] = { 0, 0, 0, 0, 1, -1 }; 
int dy[6] = { -1, 0, 1, 0, 0, 0 }; 
int dx[6] = { 0, 1, 0, -1, 0, 0 };

vector<Riped> riped;

bool isRange(int z, int y, int x) {
	return z > -1 && z < h && y > -1 && y < n && x > -1 && x < m;
}

bool isRiped() {
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					return false;
				}
			}
		}
	}
	return true;
}

int bfs() {
	int days = 0, count = 0, sibling = 0;
	int queueSize = riped.size();
	queue<Riped> Queue;
	for (int i = 0; i < riped.size(); i++) {
		Queue.push(riped[i]);
	}
	if (isRiped()) {
		return 0;
	}

	while (!Queue.empty()) {
		Riped tomato = Queue.front(); Queue.pop();
		sibling++;
		for (int i = 0; i < 6; i++) {
			int nextH = tomato.h + dh[i];
			int nextY = tomato.y + dy[i];
			int nextX = tomato.x + dx[i];
			if (isRange(nextH, nextY, nextX) && box[nextH][nextY][nextX] == 0) {
				Queue.push({ nextH, nextY, nextX });
				box[nextH][nextY][nextX] = 1;
				count++;
			}
		}
		if (queueSize == sibling) {
			queueSize = count;
			sibling = 0;
			count = 0;
			days++;
		}
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) {
					return -1;
				}
			}
		}
	}
	return days - 1;
}

int main() {
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> box[i][j][k];
				if (box[i][j][k] == 1) {
					riped.push_back({ i, j, k });
				}
			}
		}
	}
	cout << bfs();
	return 0;
}