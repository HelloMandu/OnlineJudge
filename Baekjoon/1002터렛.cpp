#include<iostream>
#include<cmath>
using namespace std;

double getLength(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int turret(int x1, int y1, int r1, int x2, int y2, int r2) {
	if (x1 == x2 && y1 == y2) {
		return r1 == r2 ? -1 : 0;
	}
	double length = getLength(x1, y1, x2, y2);
	if (length == r1 + r2 || length == abs(r1 - r2)) {
		return 1;
	}
	else if (length < r1 + r2 && length > abs(r1 - r2)) {
		return 2;
	}
	return 0;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << turret(x1, y1, r1, x2, y2, r2) << '\n';
	}
	return 0;
}