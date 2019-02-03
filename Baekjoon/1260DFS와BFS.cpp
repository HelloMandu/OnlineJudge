#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 10001
using namespace std;

bool visit[MAX];

void DepthFirstSearch(vector< vector<int> > &graph, int v) { // DFS��ȸ
	visit[v] = true; // �湮�� ���� true
	cout << v << ' ';
	for (int e = 0; e < graph[v].size(); e++) {
		if (!visit[graph[v][e]]) { // �湮���� ���� ������ ���Ͽ�
			DepthFirstSearch(graph, graph[v][e]);
		}
	}
}

void BreathFirstSearch(vector< vector<int> > &graph, int v) {
	queue<int> Queue;
	visit[v] = true; // �������� �湮
	Queue.push(v); // �������� push
	cout << '\n' << v << ' '; // BFS���������� ���� ���
	while (!Queue.empty()) { // ť�� ���� ����
		v = Queue.front(); // ���ο� ���� ���� set
		for (int e = 0; e < graph[v].size(); e++) {
			if (!visit[graph[v][e]]) {
				cout << graph[v][e] << ' ';
				visit[graph[v][e]] = true;
				Queue.push(graph[v][e]); // �湮������ push
			}
		}
		Queue.pop(); // �湮�Ϸ������ pop
	}
}

int main() {
	int n, m, start; // ������ ����, ������ ����, Ž���� ������ ����
	cin >> n >> m >> start;
	vector< vector<int> > graph(n + 1);
	for (int i = 0; i < m; i++) { // �׷��� �Է�
		int v, e;
		cin >> v >> e;
		graph[v].push_back(e); graph[e].push_back(v); // ����Է�
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end()); // �������� ������� ����
	DepthFirstSearch(graph, start);
	memset(visit, false, sizeof(bool) * n + 1); // DFS���� �湮������ �ʱ�ȭ
	BreathFirstSearch(graph, start);
	return 0;
}