#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100
using namespace std;

int arr[MAX][MAX];
int cache[MAX][MAX];

int canFinish(int n, int x = 0, int y = 0) {
	/*범위를 넘어선 경우*/
	if (x > n || y > n) {
		return false;
	}
	/*끝점에 정확히 도달 했을시*/
	else if (x == n && y == n) {
		return true;
	}
	/*해당 점을 한번이라도 방문했을시*/
	else if (cache[x][y] != -1) {
		return cache[x][y];
	}
	return cache[x][y] = canFinish(n, x + arr[x][y], y) || canFinish(n, x, y + arr[x][y]);
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		memset(arr, 0, sizeof(arr));
		memset(cache, -1, sizeof(cache));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		if (canFinish(n - 1)) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	return 0;
}