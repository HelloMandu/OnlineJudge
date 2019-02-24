#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int board[20][20];
/*ĭ�� ���� �� �ִ� �װ��� ���*/
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
		/*������ ����� ���*/
		if (ny < 0 || ny >= height || nx < 0 || nx >= width) {
			ok = false;
		}
		/*����� ��ġ�� ���*/
		else if ((board[ny][nx] += delta) > 1) {
			ok = false;
		}
	}
	return ok;
}

int coverBoard(int height, int width) {
	/*���� ä���� ���� ĭ �� ���� �������� �ִ� ĭ�� ã�´�*/
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
	/*���ĭ�� ä���� �� 1�� ��ȯ*/
	if (y == -1) {
		return 1;
	}
	int ret = 0;
	for (int type = 0; type < 4; type++) {
		/*board�� type���·� ���� �� ������ ���ȣ��*/
		if (setBoard(height, width, y, x, type, 1)) {
			ret += coverBoard(height, width);
		}
		/*������ ����� ġ��*/
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