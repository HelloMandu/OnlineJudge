#include<iostream>
#include<algorithm>
using namespace std;

struct Location {
	int x, y;
};

int main() {
	Location location[3];
	for (int i = 0; i < 3; i++) {
		cin >> location[i].x >> location[i].y;
	}
	int x = (location[0].x == location[1].x) ? location[2].x : ((location[0].x == location[2].x) ? location[1].x : location[0].x);
	int y = (location[0].y == location[1].y) ? location[2].y : ((location[0].y == location[2].y) ? location[1].y : location[0].y);
	cout << x << ' ' << y;
	return 0;
}