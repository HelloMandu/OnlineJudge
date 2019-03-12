#include<iostream>
#include<queue>
using namespace std;

void josephus(queue<int> &Queue, int n, int k) {
	for (int i = 1; i <= n; i++) {
		Queue.push(i);
	}
	while (Queue.size() > 2) {
		Queue.pop();
		for (int i = 0; i < k - 1; i++) {
			Queue.push(Queue.front());
			Queue.pop();
		}
	}
}

void printWarrior(queue<int> &Queue) {
	if (Queue.front() > Queue.back()) {
		cout << Queue.back() << ' ' << Queue.front() << '\n';
	}
	else {
		cout << Queue.front() << ' ' << Queue.back() << '\n';
	}
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, k;
		queue<int> Queue;
		cin >> n >> k;
		josephus(Queue, n, k);
		printWarrior(Queue);
	}
	return 0;
}