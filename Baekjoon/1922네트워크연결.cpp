#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

struct Node {
	int E, weight;
};

vector<vector<Node> > graph;
bool visit[1001];

struct compare {
	bool operator()(Node &a, Node &b) {
		if (a.weight == b.weight) {
			return a.E > b.E;
		}
		return a.weight > b.weight;
	}
};

void insertHeap(priority_queue<Node, vector<Node>, compare> &heap, int v) {
	for (int i = 0; i < graph[v].size(); i++) {
		if (!visit[graph[v][i].E]) {
			heap.push(graph[v][i]);
		}
	}
}

int computeMST() {
	priority_queue<Node, vector<Node>, compare> heap;
	int result = 0;
	visit[1] = true;
	insertHeap(heap, 1);
	while (!heap.empty()) {
		Node node = heap.top(); heap.pop();
		if (!visit[node.E]) {
			result += node.weight;
			visit[node.E] = true;
			insertHeap(heap, node.E);
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n;
	graph.resize(n + 1);
	cin >> m;
	while (m--) {
		int v, e, weight;
		cin >> v >> e >> weight;
		graph[v].push_back({ e, weight });
		graph[e].push_back({ v, weight });
	}
	cout << computeMST();
	return 0;
}