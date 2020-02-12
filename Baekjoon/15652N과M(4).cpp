#include<iostream>
#include<vector>
using namespace std;

int arr[9];
int n, m;

void sequence(int num = 1, int count = 0) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
		arr[count] = i;
		sequence(i, count + 1);
		arr[count] = 0;
	}
}

int main() {
	cin >> n >> m;
	sequence();
	return 0;
}