#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node {
	int edge, weight;
};

struct compare {
	bool operator()(const Node& n1, const Node& n2) {
		return n1.weight > n2.weight;
	}
};

int n, m;
int start, arrived;
vector<vector<Node> > graph;
int dis[1001];

void dijkstra() {
	priority_queue<Node, vector<Node>, compare> heap;
	heap.push({ start, 0 });
	dis[start] = 0;
	while (!heap.empty()) {
		int cur = heap.top().edge, weight = heap.top().weight;
		heap.pop();
		if (weight > dis[cur]) { continue; }
		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i].edge, nextWeight = graph[cur][i].weight;
			if (dis[next] > dis[cur] + nextWeight) {
				heap.push({ next, dis[cur] + nextWeight });
				dis[next] = dis[cur] + nextWeight;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		dis[i] = 2147483647;
	}
	graph.resize(n + 1);
	while (m--) {
		int v, e, w;
		cin >> v >> e >> w;
		graph[v].push_back({ e, w });
	}
	cin >> start >> arrived;
	dijkstra();
	cout << dis[arrived];
	return 0;
}