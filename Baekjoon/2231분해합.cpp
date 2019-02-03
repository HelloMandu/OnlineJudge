#include<iostream>
#include<algorithm>
#define MAX 1000001
using namespace std;

int Cal(int i) {
	int sum = i;
	while (i) {
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int Constructor(int n) {
	for (int i = 1; i < MAX; i++) {
		if (Cal(i) == n) {
			return i;
		}
	}
}

int main() {
	int n;
	cin >> n;
	cout << Constructor(n);
	return 0;
}