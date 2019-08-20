#include<iostream>
#include<algorithm>
#define WHITE 0
#define BLUE 1
using namespace std;

int arr[128][128];
int n, white = 0, blue = 0;

bool isConfetti(int type, int y, int x, int n) {
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
		white++;
	}
	else if (isConfetti(BLUE, y, x, n)) {
		blue++;
	}
	else {
		DivideAndConquer(y, x, n / 2);
		DivideAndConquer(y, x + n / 2, n / 2);
		DivideAndConquer(y + n / 2, x, n / 2);
		DivideAndConquer(y + n / 2, x + n / 2, n / 2);
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
	cout << white << '\n' << blue;
	return 0;
}