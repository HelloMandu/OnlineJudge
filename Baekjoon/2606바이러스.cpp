#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<vector<int> > graph;

bool isVisit[101];
int dfs(int v = 1) {
	int result = 0;
	isVisit[v] = true;
	for (int i = 0; i < graph[v].size(); i++) {
		if (!isVisit[graph[v][i]]) {
			result += dfs(graph[v][i]);
		}
	}
	return result + 1;
}

int main() {
	int n, edge;
	cin >> n >> edge;
	graph.resize(n + 1);
	while (edge--) {
		int v, e;
		cin >> v >> e;
		graph[v].push_back(e);
		graph[e].push_back(v);
	}
	cout << dfs() - 1;
	return 0;
}