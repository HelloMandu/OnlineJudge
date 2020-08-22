#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a = 1, b = 0;
	while (n--) {
		int nA = 0, nB = 0;
		nB = a;
		nA = b;
		nB += b;
		a = nA, b = nB;
	}
	cout << a << ' ' << b;
	return 0;
}