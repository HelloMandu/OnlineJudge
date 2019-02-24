#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int board[20][20];
/*칸을 덮을 수 있는 네가지 방법*/
const int coverType[4][3][2] = {
	{ { 0, 0 }, { 1, 0 }, { 0, 1 } },
	{ { 0, 0 }, { 0, 1 }, { 1, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, 1 } },
	{ { 0, 0 }, { 1, 0 }, { 1, -1 } }
};

bool setBoard(int height, int width, int y, int x, int type, int delta) {
	bool ok = true;
	for (int i = 0; i < 3; i++) {
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];
		/*범위를 벗어나는 경우*/
		if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
			ok = false;
		}
		/*블록이 겹치는 경우*/
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
}

int coverBoard(int height, int width) {
	/*아직 채우지 못한 칸 중 가장 왼쪽위에 있는 칸을 찾는다*/
	int x = -1, y = -1;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (board[i][j] == 0) {
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) {
			break;
		}
	}
	/*모든칸을 채웠을 시 1을 반환*/
	if (y == -1) {
		return 1;
	}
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		/*board를 type형태로 덮을 수 있으면 재귀호출*/
		if (setBoard(height, width, y, x, type, 1)) {
			ret += coverBoard(height, width);
		}
		/*덮었던 블록을 치움*/
		setBoard(height, width, y, x, type, -1);
	}
	return ret;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int height, width;
		cin >> height >> width;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				char temp;
				cin >> temp;
				if (temp == '#') {
					board[i][j] = 1;
				}
			}
		}
		cout << coverBoard(height, width) << '\n';
		memset(board, 0, sizeof(board));
	}
	return 0;
}