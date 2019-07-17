#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[10];
int main() {
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (arr[i] > arr[idx]) {
			idx = i;
		}
	}
	cout << arr[idx] << '\n' << idx + 1;
	return 0;
}