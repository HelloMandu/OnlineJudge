#include<iostream>
#include<cstring>
using namespace std;

int arr[301][301];
bool isVisit[301][301];
int ice = 0;
int r, c, result = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y >= 0 && y < r && x >= 0 && x < c;
}

int melt(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i], X = x + dx[i];
		if (isRange(Y, X) && !isVisit[Y][X] && arr[Y][X] == 0) {
			cnt++;
		}
	}
	return cnt;
}

int dfs(int y, int x) {
	int result = 0;
	isVisit[y][x] = false;
	for (int i = 0; i < 4; i++) {
		int Y = y + dy[i], X = x + dx[i];
		if (isRange(Y, X) && isVisit[Y][X] && arr[Y][X] > 0) {
			result += dfs(Y, X);
		}
	}
	return result + 1;
}

bool divide() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] > 0) {
				if (dfs(i, j) == ice) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] > 0) { ice++; }
		}
	}
	do {
		memset(isVisit, false, sizeof(isVisit));
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] > 0) {
					isVisit[i][j] = true;
					arr[i][j] -= melt(i, j);
					if (arr[i][j] <= 0) {
						arr[i][j] = 0;
						ice--;
					}
				}
			}
		}
		result++;
	} while (!divide());
	cout << (ice != 0 ? result : 0);
	return 0;
}