#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)

struct Node {
	int edge, capacity;
	Node* reverse;
	Node(int edge, int capacity) :edge(edge), capacity(capacity) {};
};

int level[52] = { -1, };
int sink = 25;
vector<vector<Node*> > graph(52);

bool networkFlow() {
	memset(level, -1, sizeof(level));
	queue<int> Queue;
	Queue.push(0);
	level[0] = 0;
	while (!Queue.empty()) {
		int node = Queue.front(); Queue.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			Node& next = *graph[node][i];
			if (level[next.edge] == -1 && next.capacity > 0) {
				level[next.edge] = level[node] + 1;
				Queue.push(next.edge);
			}
		}
	}
	return level[sink] != -1;
}

int renualFlow(int node = 0, int flow = 2147483647) {
	if (node == sink) { 
		return flow;
	}
	for (int i = 0; i < graph[node].size(); i++) {
		Node& next = *graph[node][i];
		if (level[next.edge] == level[node] + 1 && next.capacity > 0) {
			int f = renualFlow(next.edge, min(flow, next.capacity));
			if (f > 0) {
				next.capacity -= f;
				next.reverse->capacity += f;
				return f;
			}
		}
	}
	return 0;
}

int f(char n) {
	if (n <= 'Z') return n - 'A'; 
	return n - 'a' + 26;

}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	//freopen("input.txt", "rt", stdin);
	int n;
	cin >> n;
	while (n--) {
		char v, e; int capacity;
		cin >> v >> e >> capacity;
		Node* a = new Node(f(e), capacity);
		Node* b = new Node(f(v), capacity);
		a->reverse = b;
		b->reverse = a;
		graph[f(v)].push_back(a); graph[f(e)].push_back(b);
	}
	int result = 0;
	while (networkFlow()) {
		while (true) {
			int flow = renualFlow();
			if (flow == 0) { break; }
			result += flow;
		}
	}
	cout << result;
	return 0;
}