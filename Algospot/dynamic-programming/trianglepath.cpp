#include<bits/stdc++.h>
using namespace std;

int triangle[101][101];
int maxPath[101][101];
int n;

int getMaxPath(int y, int x){
	int &ret = maxPath[y][x];
	if(ret){
		return ret;
	} else if(y == n - 1){
		return ret = triangle[y][x];
	}  
	return maxPath[y][x] = max(getMaxPath(y + 1, x), getMaxPath(y + 1, x + 1)) + triangle[y][x];
}

int main() {
	freopen("../input.txt", "r", stdin);
	int t;
	cin >> t;
	while (t--) {
		memset(maxPath, 0, sizeof(maxPath));
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i + 1; j++) {
				cin >> triangle[i][j];
			}
		}
		cout << getMaxPath(n, 0, 0) << '\n';
	}
	return 0;
}