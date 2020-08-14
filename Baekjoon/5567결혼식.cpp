#include<iostream>
#include<vector>
using namespace std;

int n, m, result = 0;
vector<vector<int> > graph;
bool isVisit[501];

void dfs(int cur, int count) {
	if (count == 2) {
		return;
	}
	if (!isVisit[cur]) {
		result++;
	}
	isVisit[cur] = true;
	for (int i = 0; i < graph[cur].size(); i++) {
		if (!isVisit[graph[cur][i]] && graph[cur][i] != 1) {
			dfs(graph[cur][i], count + 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	graph.resize(n + 1);
	cin >> m;
	while (m--) {
		int v, e;
		cin >> v >> e;
		graph[v].push_back(e);
		graph[e].push_back(v);
	}
	for (int i = 0; i < graph[1].size(); i++) {
		dfs(graph[1][i], 0);
	}
	cout << result;
	return 0;
}