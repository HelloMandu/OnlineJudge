#include<iostream>
#include<algorithm>
using namespace std;

struct Location {
	int x, y;
};

Location location[100001];

bool compare(Location a, Location b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.x;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> location[i].x >> location[i].y;
	}
	sort(location, location + n, compare);
	for (int i = 0; i < n; i++) {
		cout << location[i].x << ' ' << location[i].y << '\n';
	}
	return 0;
}