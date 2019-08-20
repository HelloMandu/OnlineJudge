#include<iostream>
#include<algorithm>
#define WHITE '0'
#define BLACK '1'
using namespace std;

char arr[64][64];
int n;

bool isConfetti(char type, int y, int x, int n) {
	for (int i = y; i < y + n; i++) {
		for (int j = x; j < x + n; j++) {
			if (type != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void DivideAndConquer(int y, int x, int n) {
	if (n == 0) {
		return;
	}
	else if (isConfetti(WHITE, y, x, n)) {
		cout << '0';
	}
	else if (isConfetti(BLACK, y, x, n)) {
		cout << '1';
	}
	else {
		cout << '(';
		DivideAndConquer(y, x, n / 2);
		DivideAndConquer(y, x + n / 2, n / 2);
		DivideAndConquer(y + n / 2, x, n / 2);
		DivideAndConquer(y + n / 2, x + n / 2, n / 2);
		cout << ')';
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	DivideAndConquer(0, 0, n);
	return 0;
}