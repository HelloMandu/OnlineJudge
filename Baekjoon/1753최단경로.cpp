#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define INF 987654321
using namespace std;

struct Node {
	int edge, weight;
};

struct compare {
	bool operator()(Node a, Node b) {
		return a.weight > b.weight;
	}
};

int v, e, start;
vector<vector<Node> > graph;
int dis[20001];

void dijkstra() {
	priority_queue<Node, vector<Node>, compare> heap;
	dis[start] = 0;
	heap.push({ start, 0 });
	while (!heap.empty()) {
		int current = heap.top().edge, weight = heap.top().weight;
		heap.pop();
		if (dis[current] >= weight) { // ���� �Ÿ����� �߰��� �Ÿ��� �� Ŭ�� ���X
			for (int i = 0; i < graph[current].size(); i++) {
				int next = graph[current][i].edge,
					nextWeight = weight + graph[current][i].weight;
				if (nextWeight < dis[next]) {
					dis[next] = nextWeight;
					heap.push({ next, nextWeight });
				}
			}
		}
	}
}

int main() {
	cin >> v >> e >> start;
	graph.resize(v + 1);
	fill(dis, dis + v + 1, INF);
	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	dijkstra();
	for (int i = 1; i < v + 1; i++) {
		if (dis[i] == INF) {
			cout << "INF\n";
		}
		else {
			cout << dis[i] << '\n';
		}
	}
	return 0;
}