#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int top = h - y, right = w - x, down = y, left = x;
	cout << min(top, min(right, min(down, left)));
	return 0;
}