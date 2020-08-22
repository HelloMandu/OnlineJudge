#include<iostream>
#include<vector>
using namespace std;

bool map[101][101];
/*µ¿ ºÏ ¼­ ³²*/
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n; cin >> n;
	vector<int> dir;
	while (n--) {
		dir.clear();
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		map[y][x] = true;
		dir.push_back(d);
		while (g--) {
			int size = dir.size();
			for (int i = size - 1; i >= 0; i--) {
				dir.push_back((dir[i] + 1) % 4);
			}
		}
		for (int i = 0; i < dir.size(); i++) {
			y += dy[dir[i]], x += dx[dir[i]];
			map[y][x] = true;
		}
	}
	int result = 0;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				result++;
			}
		}
	}
	cout << result;
	return 0;
}