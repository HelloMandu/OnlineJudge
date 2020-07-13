#include<iostream>
using namespace std;

struct Robot {
	int y, x, dir;
};

int n, m, result = 0;
int arr[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
Robot robot;

bool isRange(int y, int x) {
	return y >= 0 && y < n && x >= 0 && x < m;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	cin >> robot.y >> robot.x >> robot.dir;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (true) {
		if (arr[robot.y][robot.x] == 0) {
			arr[robot.y][robot.x] = 2;
			result++;
		}
		bool canClean = false;
		int left = robot.dir;
		for (int i = 0; i < 4; i++) {
			left = (left + 3) % 4;
			int ly = robot.y + dy[left], lx = robot.x + dx[left];
			if (isRange(ly, lx) && arr[ly][lx] == 0) {
				canClean = true;
				robot.y = ly, robot.x = lx, robot.dir = left;
				break;
			}
		}
		if (!canClean) {
			int back = (robot.dir + 2) % 4;
			int by = robot.y + dy[back], bx = robot.x + dx[back];
			if (isRange(by, bx) && arr[by][bx] == 1) {
				cout << result;
				break;
			}
			robot.y = by, robot.x = bx;
		}
	}
	return 0;
}