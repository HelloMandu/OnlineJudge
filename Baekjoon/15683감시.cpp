#include<iostream>
#include<vector>
#include<algorithm>
#define WALL 6
using namespace std;

int map[9][9];
int n, m;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int> > cctvList;
int result = 0;

void copyMap(int map[][9], int newMap[][9]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			newMap[i][j] = map[i][j];
		}
	}
}

void look(int map[][9], pair<int, int>& cctv, int dir) {
	int cur = map[cctv.first][cctv.second];
	int y = cctv.first, x = cctv.second;
	switch (dir) {
	case 0:
		y -= 1;
		while (y >= 0 && map[y][x] != WALL) {
			if (map[y][x] > 0 && map[y][x] < WALL) {
				y--;
				continue;
			}
			map[y--][x] = -1;
		}
		break;
	case 1:
		x += 1;
		while (x < m && map[y][x] != WALL) {
			if (map[y][x] > 0 && map[y][x] < WALL) {
				x++;
				continue;
			}
			map[y][x++] = -1;
		}
		break;
	case 2:
		y += 1;
		while (y < n && map[y][x] != WALL) {
			if (map[y][x] > 0 && map[y][x] < WALL) {
				y++;
				continue;
			}
			map[y++][x] = -1;
		}
		break;
	case 3:
		x -= 1;
		while (x >= 0 && map[y][x] != WALL) {
			if (map[y][x] > 0 && map[y][x] < WALL) {
				x--;
				continue;
			}
			map[y][x--] = -1;
		}
		break;
	}
}

void traverse(int map[][9], int depth = 0) {
	if (depth == cctvList.size()) {
		int notSeek = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 0) {
					notSeek++;
				}
			}
		}
		result = min(result, notSeek);
		return;
	}
	pair<int, int>& cctv = cctvList[depth];
	int newMap[9][9] = { 0, };
	switch (map[cctv.first][cctv.second]) {
	case 1:
		for (int i = 0; i < 4; i++) {
			copyMap(map, newMap);
			look(newMap, cctv, i);
			traverse(newMap, depth + 1);
		}
		break;
	case 2:
		for (int i = 0; i < 2; i++) {
			copyMap(map, newMap);
			look(newMap, cctv, i);
			look(newMap, cctv, (i + 2) % 4);
			traverse(newMap, depth + 1);
		}
		break;
	case 3:
		for (int i = 0; i < 4; i++) {
			copyMap(map, newMap);
			look(newMap, cctv, i);
			look(newMap, cctv, (i + 1) % 4);
			traverse(newMap, depth + 1);
		}
		break;
	case 4:
		for (int i = 0; i < 4; i++) {
			copyMap(map, newMap);
			look(newMap, cctv, i);
			look(newMap, cctv, (i + 1) % 4);
			look(newMap, cctv, (i + 2) % 4);
			traverse(newMap, depth + 1);
		}
		break;
	case 5:
		copyMap(map, newMap);
		for (int i = 0; i < 4; i++) {
			look(newMap, cctv, i);
		}
		traverse(newMap, depth + 1);
		break;
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	result = n * m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] > 0 && map[i][j] < 6) {
				cctvList.push_back({ i, j });
			}
		}
	}
	traverse(map);
	cout << result;
	return 0;
}