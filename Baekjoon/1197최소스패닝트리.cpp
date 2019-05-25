#include<iostream>
#include<queue>
#define MAX 10001
using namespace std;

struct Node {
	int v, e, weight;
};

struct compare {
	bool operator()(Node &a, Node&b) {
		return a.weight > b.weight;
	}
};

priority_queue<Node, vector<Node>, compare> heap;

int getParent(int parent[], int x) {
	if (parent[x] == x) {return x;}
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a < b) {parent[b] = a;}
	else {parent[a] = b;}
}

bool findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b) {return true;}
	else {return false;}
}

int kruskal(int n) {
	int result = 0;
	int parent[MAX] = { 0 };
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	while (!heap.empty()) {
		Node node = heap.top(); heap.pop();
		if (!findParent(parent, node.v, node.e)) {
			result += node.weight;
			unionParent(parent, node.v, node.e);
		}
	}
	return result;
}

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int v, e, weight;
		cin >> v >> e >> weight;
		heap.push({ v, e, weight });
	}
	cout << kruskal(n);
	return 0;
}