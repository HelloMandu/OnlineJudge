#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101
using namespace std;

int triangle[MAX][MAX];
int maxPath[MAX][MAX];

int getMaxPath(int n, int y = 0, int x = 0) {
	/*기저사례 맨 아랫줄에 도달*/
	if (y == n - 1) {
		return triangle[y][x];
	}
	/*메모이제이션*/
	else if (maxPath[y][x]) {
		return maxPath[y][x];
	}

	return maxPath[y][x] = max(getMaxPath(n, y + 1, x), getMaxPath(n, y + 1, x + 1)) + triangle[y][x];
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> triangle[i][j];
			}
		}
		cout << getMaxPath(n) << '\n';
		memset(maxPath, 0, sizeof(maxPath));
	}
	return 0;
}