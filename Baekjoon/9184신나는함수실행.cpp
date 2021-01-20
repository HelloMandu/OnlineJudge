#include<iostream>
#include<cstring>
using namespace std;

int cache[51][51][51];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1;
	}
	else if (a > 20 || b > 20 || c > 20) {
		return w(20, 20, 20);
	}
	int& ret = cache[a][b][c];
	if (ret != -1) {
		return ret;
	}
	else if (a < b && b < c) {
		return ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	return ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	memset(cache, -1, sizeof(cache));
	int a, b, c;
	while (cin >> a >> b >> c) {
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << '\n';
	}
	return 0;
}