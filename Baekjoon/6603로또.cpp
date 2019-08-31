#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[14];
int result[14];
int n;

void dfs(int start, int count) {
	if (count == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		result[count] = arr[i];
		dfs(i + 1, count + 1);
	}
}

int main() {
	while (cin >> n) {
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		dfs(0, 0);
		cout << '\n';
	}
	return 0;
}