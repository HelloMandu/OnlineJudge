#include<iostream>
#include<queue>
using namespace std;

int main() {
	queue<int> Queue;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) // 1���� n���� ���ʴ�� push
		Queue.push(i);
	while (Queue.size() > 1) { // queue�� �ϳ��� ���� �� ����
			Queue.pop();
			Queue.push(Queue.front());
			Queue.pop();
	}
	cout << Queue.front() << '\n';
	return 0;
}