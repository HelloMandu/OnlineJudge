#include<iostream>
using namespace std;

int row, col;
int map[51][51];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };

bool isRange(int y, int x) {
	return y < row&& y >= 0 && x < col&& x >= 0;
}

void dfs(int y, int x) {
	if (map[y][x] == 0) {
		return;
	}
	map[y][x] = 0;
	for (int i = 0; i < 8; i++) {
		if (map[y + dy[i]][x + dx[i]] && isRange(y + dy[i], x + dx[i])) {
			dfs(y + dy[i], x + dx[i]);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	while (true) {
		cin >> col >> row;
		if (row == 0 && col == 0) {
			return 0;
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				cin >> map[i][j];
			}
		}
		int result = 0;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (map[i][j] == 1) {
					dfs(i, j);
					result++;
				}
			}
		}
		cout << result << '\n';
	}
	
	return 0;
}