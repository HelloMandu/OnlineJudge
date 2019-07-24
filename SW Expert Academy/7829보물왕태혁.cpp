#include<iostream>
#include<algorithm>
using namespace std;
int n;
int arr[100001];

int main() {
	int testcase;
	cin >> testcase;
	for (int i = 1; i <= testcase; i++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		cout << '#' << i << ' ' << arr[0] * arr[n - 1] << '\n';
	}
	return 0;
}