#include<iostream>
using namespace std;

int LastComputer(int a, int b) {
	int result = a;
	for (int i = 0; i < b - 1; i++)
		result = (result * a) % 10;
	return result == 0 ? 10 : result;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int a, b;
		cin >> a >> b;
		cout << LastComputer(a, b) << '\n';
	}
	return 0;
}