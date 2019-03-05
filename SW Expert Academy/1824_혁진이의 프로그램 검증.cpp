#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 21
using namespace std;

int R, C, memory;
char str[MAX][MAX];
bool isVisit[16][4][MAX][MAX];
int dx[4] = { 0, 1, 0, -1 }; // 가로
int dy[4] = { -1, 0, 1, 0 }; // 세로

bool setStr() {
	memset(isVisit, false, sizeof(isVisit));
	memset(str, 0, sizeof(str));
	memory = 0;
	bool includeAt = false;
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> str[i][j];
			if (str[i][j] == '@') {
				includeAt = true;
			}
		}
	}
	return includeAt;
}

bool isStop(int y = 0, int x = 0, int direction = 1) {
	/*중복된 접근 시 프로그램 종료불가*/
	if(isVisit[memory][direction][y][x]) { return false; }
	else { isVisit[memory][direction][y][x] = true; }

	char &present = str[y][x];
	if (present == '@') { return true; }
	else if (present >= '0' && present <= '9') { memory = present - '0'; }
	else if (present == '<') { direction = 3; }
	else if (present == '>') { direction = 1; }
	else if (present == '^') { direction = 0; }
	else if (present == 'v') { direction = 2; }
	else if (present == '_') { direction = (memory == 0) ? 1 : 3; }
	else if (present == '|') { direction = (memory == 0) ? 2 : 0; }
	else if (present == '+') {
		if (memory == 15) { memory = 0; }
		else { memory++; }
	}
	else if (str[y][x] == '-') {
		if (memory == 0) { memory = 15; }
		else { memory--; }
	}
	else if (str[y][x] == '?') {
		for (int dir = 0; dir < 4; dir++) {
			if (isStop((y + dy[dir] + R) % R, (x + dx[dir] + C) % C, dir)) {
				return true;
			}
		}
		return false;
	}
	return isStop((y + dy[direction] + R) % R, (x + dx[direction] + C) % C, direction);
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cout << '#' << t << ' ' << (setStr() && isStop() ? "YES" : "NO") << '\n';
	}
	return 0;
}