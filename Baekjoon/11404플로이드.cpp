#include<iostream>
#include<algorithm>
#define INF 987654321
using namespace std;

int n, m;
int floyd[101][101];

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
					floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
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
	return 0;
}