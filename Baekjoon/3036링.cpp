#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int ring[100];

inline int getGcd(int num1, int num2) {
	return num1 ? getGcd(num2 % num1, num1) : num2;
}

int main() {
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> ring[i];
	}
	for (int i = 1; i < n; i++) {
		int gcd = getGcd(ring[0], ring[i]);
		cout << ring[0] / gcd << '/' << ring[i] / gcd << '\n';
	}
	return 0;
}