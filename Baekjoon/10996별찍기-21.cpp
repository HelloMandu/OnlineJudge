#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n * 2; i++) {
		for (int j = 0; j < n; j++) {
			if (i % 2) {
				cout << (j % 2 ? '*' : ' ');
			}
			else {
				cout << (j % 2 ? ' ' : '*');
			}
		}
		cout << '\n';
	}
	return 0;
}