#include<iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n; cin >> n;
		int result = 0;
		int arr[1001];
		bool visit[1001] = { false, };
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
		}
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				int idx = i;
				do {
					visit[idx] = true;
					idx = arr[idx];
				} while (!visit[idx]);
				result++;
			}
		}
		cout << result << '\n';
	}
	return 0;
}