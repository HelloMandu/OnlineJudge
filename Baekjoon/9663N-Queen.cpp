#include<iostream>
#include<cmath>
using namespace std;

int arr[15];
int n;
int cnt = 0;

bool promising(int queen) {
	for (int i = 0; i < queen; i++) {
		if (arr[queen] == arr[i] || abs(arr[queen] - arr[i]) == abs(queen - i)) {
			return false;
		}
	}
	return true;
}

void NQueen(int queen) {
	if (queen == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		arr[queen] = i;
		if (promising(queen)) {
			NQueen(queen + 1);
		}
	}
}

int main() {
	cin >> n;
	NQueen(0);
	cout << cnt;
	return 0;
}