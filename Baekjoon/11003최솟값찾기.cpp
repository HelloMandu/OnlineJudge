#include<iostream>
#include<algorithm>
#include<queue>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int arr[5000001];
deque<int> Deque;
int main() {
	fastIO();
	int n, l;
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		while (!Deque.empty() && Deque.front() < i - l + 1)
			Deque.pop_front();
		while (!Deque.empty() && arr[Deque.back()] >= arr[i])
			Deque.pop_back();
		Deque.push_back(i);
		cout << arr[Deque.front()] << ' ';
	}
	return 0;
}