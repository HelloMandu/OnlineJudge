#include<iostream>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int h, w, n;
		cin >> h >> w >> n;
		if (n > h) {
			if (n % h != 0) {
				cout << n % h * 100 + (n / h) + 1 << '\n';
			}
			else {
				cout << h * 100 + (n / h) << '\n';
			}
		}
		else {
			cout << n * 100 + 1 << '\n';
		}
	}
	
	return 0;
}