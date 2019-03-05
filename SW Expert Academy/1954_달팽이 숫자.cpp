#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 10
using namespace std;

int snail[MAX][MAX];

void setSnailLine(int n, int &y, int &x, int &num, int direction) {
	switch (direction) {
	case 0:
		x++;
		while (n--) {
			snail[y][x++] = num++;
		}
		x--;
		return;
	case 1:
		y++;
		while (n--) {
			snail[y++][x] = num++;
		}
		y--;
		return;
	case 2:
		x--;
		while (n--) {
			snail[y][x--] = num++;
		}
		x++;
		return;
	case 3:
		y--;
		while (n--) {
			snail[y--][x] = num++;
		}
		y++;
		return;
	}
}

void setSnail(int n) {
	int num = 1, direction = 0;
	int y = 0, x = 0;
	setSnailLine(n, y, --x, num, direction++);
	int count = 0;
	while (n) {
		if (count++ % 2 == 0) {
			n--;
		}
		setSnailLine(n, y, x, num, direction++ % 4);
	}
}

void printSnail(int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << snail[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		int n;
		cin >> n;
		setSnail(n);
		cout << '#' << t << '\n';
		printSnail(n);
	}
	return 0;

}