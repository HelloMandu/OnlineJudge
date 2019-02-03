#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#define MAX 10001
using namespace std;

bool visit[MAX];

void DepthFirstSearch(vector< vector<int> > &graph, int v) { // DFS순회
	visit[v] = true; // 방문한 정점 true
	cout << v << ' ';
	for (int e = 0; e < graph[v].size(); e++) {
		if (!visit[graph[v][e]]) { // 방문하지 않은 정점에 한하여
			DepthFirstSearch(graph, graph[v][e]);
		}
	}
}

void BreathFirstSearch(vector< vector<int> > &graph, int v) {
	queue<int> Queue;
	visit[v] = true; // 시작정점 방문
	Queue.push(v); // 시작정점 push
	cout << '\n' << v << ' '; // BFS시작정점을 먼저 출력
	while (!Queue.empty()) { // 큐가 빌때 까지
		v = Queue.front(); // 새로운 시작 정점 set
		for (int e = 0; e < graph[v].size(); e++) {
			if (!visit[graph[v][e]]) {
				cout << graph[v][e] << ' ';
				visit[graph[v][e]] = true;
				Queue.push(graph[v][e]); // 방문한정점 push
			}
		}
		Queue.pop(); // 방문완료된정점 pop
	}
}

int main() {
	int n, m, start; // 정점의 갯수, 간선의 갯수, 탐색을 시작할 정점
	cin >> n >> m >> start;
	vector< vector<int> > graph(n + 1);
	for (int i = 0; i < m; i++) { // 그래프 입력
		int v, e;
		cin >> v >> e;
		graph[v].push_back(e); graph[e].push_back(v); // 양방입력
	}
	for (int i = 1; i <= n; i++)
		sort(graph[i].begin(), graph[i].end()); // 도착정점 순서대로 정렬
	DepthFirstSearch(graph, start);
	memset(visit, false, sizeof(bool) * n + 1); // DFS이후 방문한정점 초기화
	BreathFirstSearch(graph, start);
	return 0;
}