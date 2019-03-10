#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101
using namespace std;

int countCache[MAX][MAX];
int pathCache[MAX][MAX];
int triangle[MAX][MAX];
int n;

void input() {
	memset(countCache, -1, sizeof(countCache));
	memset(pathCache, -1, sizeof(pathCache));
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i + 1; j++) {
			cin >> triangle[i][j];
		}
	}
}

int getMaxPath(int y = 0, int x = 0) {
	if (y == n - 1) {
		return triangle[y][x];
	}
	int &ret = pathCache[y][x];
	if (ret != -1) {
		return pathCache[y][x];
	}
	return ret = max(getMaxPath(y + 1, x), getMaxPath(y + 1, x + 1)) + triangle[y][x];
}

int getMaxCount(int y = 0, int x = 0) {
	/*기저사례*/
	if (y == n - 1) {
		return 1;
	}
	/*메모이제이션*/
	int &ret = countCache[y][x];
	if (ret != -1) {
		return countCache[y][x];
	}
	ret = 0; // 경로를 0으로 초기화
	/*경로의 길이가 더 크거나 같은 경우의 count를 더해줌*/
	if (getMaxPath(y + 1, x) >= getMaxPath(y + 1, x + 1)) {
		ret += getMaxCount(y + 1, x);
	}
	if (getMaxPath(y + 1, x) <= getMaxPath(y + 1, x + 1)) {
		ret += getMaxCount(y + 1, x + 1);
	}
	return ret;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		input();
		cout << getMaxCount() << '\n';
	}
	return 0;
}