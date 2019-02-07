#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	priority_queue<int, vector<int>, less<int> > Max_heap; // 최대힙
	int n, integer;
	cin >> n; // 연산의 개수
	while (n--) {
		cin >> integer; // 정수입력
		if (integer) {
			Max_heap.push(integer);
		}
		else {
			if (Max_heap.empty())
				cout << "0\n";
			else {
				cout << Max_heap.top() << '\n';
				Max_heap.pop();
			}

		}
	}
	return 0;
}