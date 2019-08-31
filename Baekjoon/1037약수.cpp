#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n, arr[51];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cout << arr[0] * arr[n - 1];
	return 0;
}