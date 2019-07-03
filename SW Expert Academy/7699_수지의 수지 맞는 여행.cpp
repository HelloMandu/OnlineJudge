#include<iostream>
#include<cstring>
#define MAX 21
using namespace std;

char island[MAX][MAX];
bool alphabet[26];
int testcase, r, c, result;
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };

void input() {
	result = 0;
	memset(alphabet, false, sizeof(alphabet));
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> island[i][j];
		}
	}
}

bool isRange(int row, int col) {
	return row > -1 && row < r && col > -1 && col < c;
}

void computeMaxIsland(int row = 0, int col = 0, int count = 1) {
	if (count > result) {
		result = count;
	}
	alphabet[island[row][col] - 'A'] = true;
	for (int i = 0; i < 4; i++) {
		if (isRange(row + dy[i], col + dx[i])) {
			char &next = island[row + dy[i]][col + dx[i]];
			if (!alphabet[next - 'A']) {
				computeMaxIsland(row + dy[i], col + dx[i], count + 1);
				alphabet[next - 'A'] = false;
			}
		}
	}
}

int main() {
	cin >> testcase;
	for(int i = 0; i < testcase; i++) {
		input();
		computeMaxIsland();
		cout << "#" << i + 1 << ' ' << result << '\n';
	}
	return 0;
}