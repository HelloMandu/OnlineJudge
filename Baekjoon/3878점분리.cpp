#include<iostream>
#include<algorithm>
#include<stack>
#include<vector>
#include<cstring>
using namespace std;
#pragma warning(disable:4996)

struct Point {
	int x, y, dx, dy;
	bool operator<(const Point &a) {
		if (dx * a.dy != dy * a.dx) {
			return dx * a.dy > dy * a.dx;
		}
		else if (y != a.y) {
			return y < a.y;
		}
		return x < a.x;
	}
	bool operator<=(const Point &a) {
		if (x == a.x) {
			return y <= a.y;
		}
		return x <= a.x;
	}
	bool operator==(const Point &a) {
		return x == a.x && y == a.y;
	}
};

Point black[101], white[101];

int ccw(Point pivot, Point a, Point b) {
	long long n = 1LL * pivot.x * a.y + a.x * b.y + b.x * pivot.y - 1LL * pivot.y * a.x - a.y * b.x - b.y * pivot.x;
	if (n > 0) {
		return 1;
	}
	else if (n < 0) {
		return -1;
	}
	return 0;
}

vector<Point> convexHull(Point arr[], int size) {
	stack<int> Stack;
	int next = 0;
	Stack.push(next++);
	Stack.push(next++);
	while (next < size) {
		while (Stack.size() >= 2) {
			int second = Stack.top(); Stack.pop();
			int first = Stack.top();
			if (ccw(arr[first], arr[second], arr[next]) > 0) {
				Stack.push(second);
				break;
			}
		}
		Stack.push(next++);
	}
	vector<Point> result(Stack.size());
	for (int i = result.size() - 1; i >= 0; i--) {
		result[i] = arr[Stack.top()];
		Stack.pop();
	}
	return result;
}

bool isIntersect(Point a, Point b, Point c, Point d) {
	int ab = ccw(a, b, c) * ccw(a, b, d),
		cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (b < a) { swap(a, b); }
		if (d < c) { swap(c, d); }
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}

bool between(Point a, Point b, Point pivot) {
	if (ccw(pivot, a, b) != 0) {
		return 0;
	}
	if (a.x != b.x) {
		return a.x <= pivot.x && pivot.x <= b.x
			|| b.x <= pivot.x && pivot.x <= a.x;
	}
	else {
		return a.y <= pivot.y && pivot.y <= b.y
			|| b.y <= pivot.y && pivot.y <= a.y;
	}
}

bool isCrossing(Point pivot, Point a, Point b) {
	return a.y < pivot.y && b.y >= pivot.y && ccw(a, b, pivot) > 0;
}

int insidePolygon(vector<Point> &hull, Point pivot) {
	int crossings = 0;
	for (int i = 0; i < hull.size(); i++) {
		int next = (i + 1) % hull.size();
		if (hull[i] == hull[next]) {
			continue;
		}
		if (between(hull[i], hull[next], pivot)) {
			return 1;
		}
		else if (isCrossing(pivot, hull[i], hull[next])
			|| isCrossing(pivot, hull[next], hull[i])) {
			crossings++;
		}
	}
	return crossings % 2;
}

bool isCrash(vector<Point> &blackHull, vector<Point> &whiteHull) {
	for (int i = 0; i < blackHull.size(); i++) {
		if (insidePolygon(whiteHull, blackHull[i])) {
			return true;
		}
	}
	for (int i = 0; i < whiteHull.size(); i++) {
		if (insidePolygon(blackHull, whiteHull[i])) {
			return true;
		}
	}
	for (int i = 0; i < blackHull.size(); i++) {
		int a = i, b = (i + 1) % blackHull.size();
		if (blackHull[a] == blackHull[b]) {
			continue;
		}
		for (int j = 0; j < whiteHull.size(); j++) {
			int c = j, d = (j + 1) % whiteHull.size();
			if (whiteHull[c] == whiteHull[d]) {
				continue;
			}
			if (isIntersect(blackHull[a], blackHull[b], whiteHull[c], whiteHull[d])) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(black, 0, sizeof(black));
		memset(white, 0, sizeof(white));
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cin >> black[i].x >> black[i].y;
		}
		for (int i = 0; i < m; i++) {
			cin >> white[i].x >> white[i].y;
		}
		if (n <= 1 && m <= 1) {
			cout << "YES\n";
			continue;
		}
		sort(black, black + n);
		sort(white, white + m);
		for (int i = 1; i < n; i++) {
			black[i].dx = black[i].x - black[0].x;
			black[i].dy = black[i].y - black[0].y;
		}
		for (int i = 1; i < m; i++) {
			white[i].dx = white[i].x - white[0].x;
			white[i].dy = white[i].y - white[0].y;
		}
		sort(black + 1, black + n);
		sort(white + 1, white + m);
		vector<Point> blackHull = convexHull(black, n);
		vector<Point> whiteHull = convexHull(white, m);
		cout << (!isCrash(blackHull, whiteHull) ? "YES\n" : "NO\n");
		blackHull.clear();
		whiteHull.clear();
	}
	return 0;
}