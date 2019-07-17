#include<iostream>
using namespace std;

bool isRightTriangle(int a, int b, int c) {
	if (a * a + b * b == c * c) {
		return true;
	}
	else if (b * b + c * c == a * a) {
		return true;
	}
	else if (a * a + c * c == b * b) {
		return true;
	}
	return false;
}


int main() {
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == 0 && b == 0 && c == 0) {
			return 0;
		}
		cout << (isRightTriangle(a, b, c) ? "right" : "wrong") << '\n';
	}
}