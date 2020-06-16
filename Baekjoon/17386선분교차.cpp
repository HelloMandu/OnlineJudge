/*failed*/
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long lint;

struct Location {
	lint x, y;
	bool operator>(const Location &a) {
		if (x == a.x) {
			return y > a.y;
		}
		return x > a.x;
	}
	bool operator<(const Location &a) {
		if (x == a.x) {
			return y < a.y;
		}
		return x < a.x;
	}
	bool operator<=(const Location &a) {
		if (x == a.x) {
			return y <= a.y;
		}
		return x <= a.x;
	}
	bool operator==(const Location &a) {
		return x == a.x && y == a.y;
	}
};

inline lint ccw(Location pivot, Location a, Location b) {
	lint result = 1LL * pivot.x * a.y + a.x * b.y + b.x * pivot.y - 1LL * pivot.x * b.y - a.x * pivot.y - b.x * a.y;
	if (result > 0) { return 1; }
	else if (result < 0) { return -1;}
	return 0;
}

bool between(Location hole, Location edge1, Location edge2) {
	if (ccw(hole, edge1, edge2) != 0) {
		return false;
	}
	if (edge1.x != edge2.x) {
		return edge1.x <= hole.x && hole.x <= edge2.x
			|| edge2.x <= hole.x && hole.x <= edge1.x;
	}
	else {
		return edge1.y <= hole.y && hole.y <= edge2.y
			|| edge2.y <= hole.y && hole.y <= edge1.y;
	}
}

bool isIntersect(Location a, Location b, Location c, Location d) {/*여기만고치면댐*/
	lint ab = ccw(a, b, c) * ccw(a, b, d),
		cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b < a) { swap(a, b); }
		if (d < c) { swap(c, d); }
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

int main() {
	Location a, b, c, d;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
	cout << isIntersect(a, b, c, d);
	return 0;
}
