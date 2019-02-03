#include<iostream>
#include<queue>
using namespace std;

struct Document {
	int index; // ã���� �ϴ� ������ ��ȣ
	int important; // ã���� �ϴ� ������ �߿䵵
};

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, index, important; // ������ ��, �ñ��� ����
		queue<Document> Queue;
		priority_queue<int, vector<int>, less<int> > Heap;
		cin >> n >> index;
		for (int i = 0; i < n; i++) {
			cin >> important;
			Queue.push({ i, important });
			Heap.push(important);
		}
		int count = 0;
		while (true) {
			if (Heap.top() == Queue.front().important) { // ť�� front�� �켱������ ���� ���� ��
				if (index == Queue.front().index) { // �ñ��� ������ ���� ��
					cout << ++count << '\n';
					break;
				}
				else { // ť���� �켱������ ���� ���� ������ ��������
					Heap.pop();
					Queue.pop();
					count++;
				}
			}
			else { // �켱������ �����ʾ� �ڷ� �̵�
				Queue.push(Queue.front());
				Queue.pop();
			}
		}
	}
	return 0;
}