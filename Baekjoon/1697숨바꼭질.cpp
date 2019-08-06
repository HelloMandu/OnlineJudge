#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

int n, k;
int visit[100001];

int bfs() {
	queue<int> Queue;
	Queue.push(n);
	visit[n] = 1;
	while (!Queue.empty()) {
		int front = Queue.front(); Queue.pop();
		if (front == k) {
			return visit[front] - 1;
		}
		if (front * 2 < 100001 && visit[front * 2] == 0) {
			Queue.push(front * 2);
			visit[front * 2] = visit[front] + 1;
		}
		if (front + 1 < 100001 && visit[front + 1] == 0) {
			Queue.push(front + 1);
			visit[front + 1] = visit[front] + 1;
		}
		if (front - 1 > -1 && visit[front - 1] == 0) {
			Queue.push(front - 1);
			visit[front - 1] = visit[front] + 1;
		}
	}
}

int main() {
	cin >> n >> k;
	cout << bfs();
	return 0;
}