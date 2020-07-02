#include<iostream>
using namespace std;

bool arr[10][10][10];
char num[4];
int strike, ball;

int hasBall(char n) {
	for (int i = 0; i < 3; i++) {
		if (num[i] == n) {
			return i;
		}
	}
	return -1;
}

bool insCandidate(char a, char b, char c) {
	int st = 0, ba = 0;
	int n = hasBall(a);
	if (n != -1) {
		if (a == num[0]) {
			st++;
		}
		else {
			ba++;
		}
	}
	n = hasBall(b);
	if (n != -1) {
		if (b == num[1]) {
			st++;
		}
		else {
			ba++;
		}
	}
	n = hasBall(c);
	if (n != -1) {
		if (c == num[2]) {
			st++;
		}
		else {
			ba++;
		}
	}
	return st == strike && ba == ball;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int cnt = 0;
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			for (int k = 1; k < 10; k++) {
				if (i == j || j == k || i == k) {
					arr[i][j][k] = true;
				}
				else {
					cnt++;
				}
			}
		}
	}
	int n;
	cin >> n;
	while (n--) {
		cin >> num >> strike >> ball;
		for (int i = 1; i < 10; i++) {
			for (int j = 1; j < 10; j++) {
				for (int k = 1; k < 10; k++) {
					if (!arr[i][j][k]) {
						if (!insCandidate(i + '0', j + '0', k + '0')) {
							arr[i][j][k] = true;
							cnt--;
						}
					}
				}
			}
		}
	}
	cout << cnt;
	return 0;
}