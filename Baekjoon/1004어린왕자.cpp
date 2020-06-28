#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, sx, sy, ex, ey, cnt = 0;
		cin >> sx >> sy >> ex >> ey;
		cin >> n;
		while (n--) {
			int x, y, r;
			cin >> x >> y >> r;
			int dis1 = (sx - x) * (sx - x) + (sy - y) * (sy - y);
			int dis2 = (ex - x) * (ex - x) + (ey - y) * (ey - y);
			bool flag1 = dis1 < r * r;
			bool flag2 = dis2 < r * r;
			if (flag1 != flag2) {
				cnt++;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}