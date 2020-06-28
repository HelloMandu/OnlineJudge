#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<vector<int> > graph;
int degree[1001];
int time[1001];
int finish[1001];
int End;

int getResult(int n) {
	queue<int> Queue;
	int result = 0;
	for (int i = 1; i <= n; i++) {
		if (degree[i] == 0) {
			Queue.push(i);
			finish[i] = time[i];
		}
	}
	while (!Queue.empty()) {
		int node = Queue.front(); Queue.pop();
		for (int i = 0; i < graph[node].size(); i++) {
			int &next = graph[node][i];
			if (--degree[next] == 0) {
				Queue.push(next);
			}
			if (finish[next] < finish[node] + time[next]) {
				finish[next] = finish[node] + time[next];
			}
		}
	}
	return finish[End];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(finish, 0, sizeof(finish));
		int n, k;
		cin >> n >> k;
		graph.resize(n + 1);
		for (int i = 1; i <= n; i++) {
			cin >> time[i];
		}
		while (k--) {
			int v, e;
			cin >> v >> e;
			graph[v].push_back(e);
			degree[e]++;
		}
		cin >> End;
		cout << getResult(n) << '\n';
		graph.clear();
	}
	return 0;
}