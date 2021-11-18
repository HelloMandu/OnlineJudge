#include<bits/stdc++.h>
using namespace std;

int n, m, k;
bool arr[101][101];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x) {
	return y < n && y > -1 && x < m && x > -1;
}

int dfs(int y, int x) {
	int result = 0;
    arr[y][x] = true;
    for(int i = 0; i < 4; i++){
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (isRange(nextY, nextX) && !arr[nextY][nextX]) {
			result += dfs(nextY, nextX);
		}
	}
	return result + 1;
}

int main() {
    vector<int> result;
	cin >> n >> m >> k;
    while(k--){
        int sy, sx, ey, ex;
        cin >> sx >> sy >> ex >> ey;
        for(int i = sy; i < ey; ++i){
            for(int j = sx; j < ex; ++j){
                arr[i][j] = true;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(!arr[i][j]){
                result.push_back(dfs(i, j));
            }
        }
    }
	sort(result.begin(), result.end());
	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}