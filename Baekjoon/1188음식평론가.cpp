#include<iostream>
using namespace std;

int gcd(int n, int m) {
	return m ? gcd(m, n % m) : n;
}

int main() {
	int n, m;
	cin >> n >> m;
	cout << m - gcd(n, m);
	return 0;
}