#include<iostream>
#include<vector>
using namespace std;

int arr[9];
int n, m;

void sequence(int count = 0) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[count] = i;
		sequence(count + 1);
		arr[count] = 0;
	}
}

int main() {
	cin >> n >> m;
	sequence();
	return 0;
}