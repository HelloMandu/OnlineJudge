#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n;
string map[26];
bool isVisit[26][26];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y < n && y > -1 && x < n && x > -1;
}

int dfs(int y, int x) {
	int result = 0;
	isVisit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (isRange(nextY, nextX) && !isVisit[nextY][nextX] && map[nextY][nextX] == '1') {
			result += dfs(nextY, nextX);
		}
	}
	return result + 1;
}

int main() {
	vector<int> result;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isVisit[i][j] && map[i][j] == '1') {
				result.push_back(dfs(i, j));
			}
		}
	}
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	return 0;
}