#include<iostream>
#include<algorithm>
using namespace std;
int n, arr[1001];
int main() {
	int count = 0;
	for (int i = 0; i < 10; i++) {
		cin >> n;
		arr[n % 42]++;
	}
	for (int i = 0; i < 1001; i++) {
		if (arr[i] > 0) {
			count++;
		}
	}
	cout << count;
	return 0;
}