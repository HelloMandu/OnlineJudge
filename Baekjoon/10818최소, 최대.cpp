#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[1000001];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[0] << ' ' << arr[n - 1];
	return 0;
}