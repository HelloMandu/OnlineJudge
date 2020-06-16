#include<iostream>
using namespace std;

bool arr[10001];

int isSelf(int n) {
	int sum = n;
	while (n) {
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

void selfNumber() {
	for (int i = 1; i < 10001; i++) {
		int n = isSelf(i);
		if (n <= 10000) {
			arr[n] = true;
		}
	}
}

int main() {
	selfNumber();
	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) {
			cout << i << '\n';
		}
	}
	return 0;
}