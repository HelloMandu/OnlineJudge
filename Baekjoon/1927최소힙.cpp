#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	priority_queue<int, vector<int>, greater<int> > Min_heap; // 최소힙
	int n, integer;
	cin >> n; // 연산의 개수
	while (n--) {
		cin >> integer; // 정수입력
		if (integer) {
			Min_heap.push(integer);
		}
		else {
			if (Min_heap.empty())
				cout << "0\n";
			else {
				cout << Min_heap.top() << '\n';
				Min_heap.pop();
			}
				
		}
	}
	return 0;
}