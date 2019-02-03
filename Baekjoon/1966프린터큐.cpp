#include<iostream>
#include<queue>
using namespace std;

struct Document {
	int index; // 찾고자 하는 문서의 번호
	int important; // 찾고자 하는 문서의 중요도
};

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, index, important; // 문서의 수, 궁금한 문서
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
			if (Heap.top() == Queue.front().important) { // 큐의 front가 우선순위가 가장 높을 때
				if (index == Queue.front().index) { // 궁금한 문서가 같을 때
					cout << ++count << '\n';
					break;
				}
				else { // 큐에서 우선순위가 가장 높은 문서가 빠져나감
					Heap.pop();
					Queue.pop();
					count++;
				}
			}
			else { // 우선순위가 높지않아 뒤로 이동
				Queue.push(Queue.front());
				Queue.pop();
			}
		}
	}
	return 0;
}