#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> Queue;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) // 1부터 n까지 차례대로 push
		Queue.push(i);
	while (Queue.size() > 1) { // queue에 하나가 남을 때 까지
			Queue.pop();
			Queue.push(Queue.front());
			Queue.pop();
	}
	cout << Queue.front() << '\n';
	return 0;
}