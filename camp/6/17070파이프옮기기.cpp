#include<bits/stdc++.h>
using namespace std;

int n, home[17][17], ans;
int dy[3] = { 1, 0, 1 };
int dx[3] = { 0, 1, 1 };
int action[3][3] = { {0, 2, -1}, {1, 2, -1}, {0, 1, 2} };
// type 0 : 가로, 1 : 세로, 2 : 대각
void recur(int x, int y, int type) {
	for (int d = 0; d < 3 && action[type][d] != -1; d++) {
		int nextY = y + dy[action[type][d]];
		int nextX = x + dx[action[type][d]];

		if (nextX < 1 || nextY < 1 || nextX > n || nextY > n || home[nextX][nextY])
			continue;

		if (action[type][d] == 2 && (home[nextX - 1][nextY] || home[nextX][nextY - 1]))
			continue;

		if (nextX == n && nextY == n) {
			++ans;
			continue;
		}
		recur(nextX, nextY, action[type][d]);
	}
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= n; j++){
			cin >> home[i][j];
        }
    }
	if(!home[n][n]) {
        recur(1, 2, 0);
    }
	cout << ans;
	return 0;
}