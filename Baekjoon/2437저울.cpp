#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (sum + 1 < arr[i]) {
			break;
		}
		sum += arr[i];
	}
	cout << sum + 1;
	return 0;
}