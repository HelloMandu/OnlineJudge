#include<iostream>
using namespace std;

inline int getGcd(int a, int b) {
	return a ? getGcd(b % a, a) : b;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n1, n2;
		cin >> n1 >> n2;
		int gcd = getGcd(n1, n2);
		cout << n1 / gcd * n2 << ' ' << gcd << '\n';
	}
	return 0;
}