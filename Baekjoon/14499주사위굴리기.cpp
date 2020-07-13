#include<iostream>
using namespace std;

int n, m, y, x, k ,dir;
int arr[21][21];
int dice[6];
int dy[4] = { 0, 0, -1, 1 };
int dx[4] = { 1, -1, 0, 0 };

void rotate(int dir) {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = dice[i];
	}
	switch (dir) {
	case 1:
		dice[0] = temp[2];
		dice[2] = temp[5];
		dice[3] = temp[0];
		dice[5] = temp[3];
		break;
	case 2:
		dice[0] = temp[3];
		dice[2] = temp[0];
		dice[3] = temp[5];
		dice[5] = temp[2];
		break;
	case 3:
		dice[0] = temp[1];
		dice[1] = temp[5];
		dice[4] = temp[0];
		dice[5] = temp[4];
		break;
	case 4:
		dice[0] = temp[4];
		dice[1] = temp[0];
		dice[4] = temp[5];
		dice[5] = temp[1];
		break;
	}
}

bool isRange(int y, int x) {
	return y >= 0 && y < n&& x >= 0 && x < m;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (k--) {
		cin >> dir;
		if (isRange(y + dy[dir - 1], x + dx[dir - 1])) {
			y += dy[dir - 1], x += dx[dir - 1];
			rotate(dir);
			if (arr[y][x] == 0) {
				arr[y][x] = dice[0];
			}
			else {
				dice[0] = arr[y][x];
				arr[y][x] = 0;
			}
			cout << dice[5] << '\n';
		}
	}
	return 0;
}