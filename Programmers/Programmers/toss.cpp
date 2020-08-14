#include <iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;

int map[10001][10001];
bool isVisit[10001][10001];
string str;
int row = 0, col = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y >= 0 && y < row&& x >= 0 && x < col;
}

void bfs(int y, int x, int& result) {
	queue<pair<int, int> > Queue;
	Queue.push({ y, x });
	while (!Queue.empty()) {
		pair<int, int> cur = Queue.front(); Queue.pop();
		if (isVisit[cur.first][cur.second]) { continue; }
		isVisit[cur.first][cur.second] = true;
		for (int i = 0; i < 4; i++) {
			int Y = cur.first + dy[i],
				X = cur.second + dx[i];
			if (!isVisit[Y][X] && isRange(Y, X)) {
				if (map[Y][X] == 0) {
					result++;
				}
				else {
					Queue.push({ Y, X });
				}
			}
		}
	}
}

int solution() {
	int result = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (!isVisit[i][j] && map[i][j] == 1) {
				bfs(i, j, result);
			}
		}
	}
	return result;
}

int main() {
	getline(cin, str);
	int i = 0;
	while (i < str.size()) {
		if (str[i] != ' ') {
			map[row][col++] = str[i] - '0';
		}
		if (str[i] == ';') {
			row++;
			col = 0;
		}
		i++;
	}
	row++;
	//for (int i = 0; i < row; i++) {
	//    for (int j = 0; j < col; j++) {
	//        cout << map[i][j] << ' ';
	//    }
	//    cout << '\n';
	//}
	cout << solution();
	return 0;
}