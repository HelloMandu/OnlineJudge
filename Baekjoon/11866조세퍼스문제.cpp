#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n, m;
	queue<int> Queue;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		Queue.push(i);
	cout << '<';
	while (!Queue.empty()) {
		for (int i = 1; i < m; i++) {
			Queue.push(Queue.front());
			Queue.pop();
		}
		cout << Queue.front();
		Queue.pop();
		if (!Queue.empty())
			cout << ", ";
	}
	cout << '>';
	return 0;
}