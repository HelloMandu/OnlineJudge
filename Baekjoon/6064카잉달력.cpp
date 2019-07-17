#include<iostream>
using namespace std;

int getGcd(int num1, int num2) {
	return num1 ? getGcd(num2 % num1, num1) : num2;
}

int getMaxYear(int M, int N) {
	int gcd;
	if (M < N) {
		gcd = getGcd(M, N);
	}
	else {
		gcd = getGcd(N, M);
	}
	return M / gcd * N;
}

int kaing(int M, int N, int X, int Y) {
	int maxYear = getMaxYear(M, N);
	int result = X;
	int x = X, y = X % N;
	if (y == 0) y = N;
	while (result <= maxYear) {
		if (x == X && y == Y) {
			return result;
		}
		result += M;
		y = (y + M) % N;
		if (y == 0) y = N;
	}
	return -1;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int M, N, X, Y;
		cin >> M >> N >> X >> Y;
		cout << kaing(M, N, X, Y) << '\n';
	}
	return 0;
}