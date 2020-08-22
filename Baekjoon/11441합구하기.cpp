#include<iostream>
using namespace std;

int n, arr[100001];
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	cin >> n;
	while (n--) {
		int start, end;
		cin >> start >> end;
		cout << arr[end] - arr[start - 1] << '\n';
	}
	return 0;
}