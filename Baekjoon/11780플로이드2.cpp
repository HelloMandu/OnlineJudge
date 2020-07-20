#include<iostream>
#include<algorithm>
#include<vector>
#define INF 987654321
using namespace std;

int n, m;
int floyd[101][101];
int path[101][101];
vector<int> route;

void findRoute(int i, int j) {
	if (path[i][j]) {
		findRoute(i, path[i][j]);
		route.push_back(path[i][j]);
		findRoute(path[i][j], j);
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			floyd[i][j] = INF;
		}
	}
	while (m--) {
		int v, e, w;
		cin >> v >> e >> w;
		floyd[v][e] = min(floyd[v][e], w);
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					if (floyd[i][j] > floyd[i][k] + floyd[k][j]) {
						floyd[i][j] = floyd[i][k] + floyd[k][j];
						path[i][j] = k;
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << (floyd[i][j] == INF ? 0 : floyd[i][j]) << ' ';
		}
		cout << '\n';
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				cout << "0\n";
			}
			else {
				route.clear();
				findRoute(i, j);
				cout << route.size() + 2 << ' ' << i << ' ';
				for (int i = 0; i < route.size(); i++) {
					cout << route[i] << ' ';
				}
				cout << j << '\n';
			}
		}
	}
	return 0;
}