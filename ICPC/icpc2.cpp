#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<cstdlib>
#include<string>
#include<stack>
#include<queue>
using namespace std;

struct Info {
	int y, x, weight;
};

struct compare {
	bool operator()(Info& a, Info& b) {
		return a.weight > b.weight;
	}
};

priority_queue<Info, vector<Info>, compare> heap;

int arr[1001][1001];
int n, m;
int dis[1001][1001];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y < n&& y > -1 && x < m&& x > -1;
}

int bfs() {
	int y = 0, x = 0;
	dis[0][0] = arr[0][0];
	heap.push({ y, x, arr[0][0] });
	while (!heap.empty()) {
		y = heap.top().y; x = heap.top().x;
		if (y == n - 1 && x == m - 1) {
			return dis[n - 1][m - 1];
		}
		for (int i = 0; i < 4; i++) {
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (isRange(nextY, nextX) && arr[nextY][nextX] != -1) {
				dis[nextY][nextX] += (dis[y][x] + arr[nextY][nextX]);
				heap.push({ nextY, nextX, dis[y][x] + arr[nextY][nextX] });
				arr[nextY][nextX] = -1;
			}
		}
		heap.pop();
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	cout << bfs();
	
	return 0;
}