#include<iostream>
using namespace std;

void multiply(int num1, int num2) {
	int mod = 10, n;
	for (int i = 0; i < 3; i++) {
		n = num2 % 10;
		cout << num1 * n << '\n';
		num2 /= mod;
	}
}

int main() {
	int num1, num2;
	cin >> num1 >> num2;
	multiply(num1, num2);
	cout << num1 * num2;
	return 0;
}