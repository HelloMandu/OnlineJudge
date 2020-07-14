#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Loc {
	int y, x, depth = 0;
};

int n, m;
int arr[51][51];
int dis[51][51];
int dy[8] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dx[8] = { -1, 0, 1, 1, 1, 0, -1, -1 };
vector<Loc> sharks;

bool isRange(Loc loc) {
	return loc.y >= 0 && loc.y < n&& loc.x >= 0 && loc.x <= m;
}

void traverse(Loc loc) {
	queue<Loc> Queue;
	bool isVisit[51][51] = { false, };
	Queue.push(loc);
	while (!Queue.empty()) {
		Loc cur = Queue.front(); Queue.pop();
		isVisit[cur.y][cur.x] = true;
		for (int i = 0; i < 8; i++) {
			Loc next = { cur.y + dy[i], cur.x + dx[i], cur.depth + 1 };
			if (isRange(next) && !isVisit[next.y][next.x] && dis[next.y][next.x] > next.depth) {
				dis[next.y][next.x] = next.depth;
				isVisit[next.y][next.x] = true;
				Queue.push(next);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dis[i][j] = 2147483647;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				sharks.push_back({ i, j, 0 });
				dis[i][j] = 0;
			}
		}
	}
	for (int i = 0; i < sharks.size(); i++) {
		traverse(sharks[i]);
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			result = max(result, dis[i][j]);
		}
	}
	cout << result;
	return 0;
}