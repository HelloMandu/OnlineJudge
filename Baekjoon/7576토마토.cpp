#include<iostream>
#include<queue>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1001
using namespace std;

struct Riped {
	int y, x;
};

int tomatoes[MAX][MAX];
int row, col;
queue<Riped> ripedTomatoes;
int y[4] = { -1, 0, 1, 0 };
int x[4] = { 0, 1, 0, -1 };

void input() {
	cin >> col >> row;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> tomatoes[i][j];
			if (tomatoes[i][j] == 1) {
				ripedTomatoes.push({ i, j });
			}
		}
	}
}

int getMinRipedDays() {
	int days = 0, count = 0, sibling = 0;
	int queueSize = ripedTomatoes.size();
	/*모두 익어있는 상태*/
	if (queueSize == 0) {
		return days;
	}
	while (!ripedTomatoes.empty()) {
		Riped riped = ripedTomatoes.front();
		sibling++;
		for (int i = 0; i < 4; i++) {
			if (riped.y + y[i] > -1 && riped.y + y[i] < row && riped.x + x[i] > -1 && riped.x + x[i] < col) {
				if (tomatoes[riped.y + y[i]][riped.x + x[i]] == 0) {
					tomatoes[riped.y + y[i]][riped.x + x[i]] = 1;
					ripedTomatoes.push({ riped.y + y[i] , riped.x + x[i] });
					count++;
				}
			}
		}
		ripedTomatoes.pop();
		if (queueSize == sibling) {
			queueSize = count;
			sibling = 0;
			count = 0;
			days++;
		}
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (tomatoes[i][j] == 0) {
				return -1;
			}
		}
	}
	return days - 1;
}

int main() {
	fastIO();
	input();
	cout << getMinRipedDays();
	return 0;
}