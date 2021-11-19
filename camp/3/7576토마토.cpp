#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[1001][1001];
int totalTomatoes = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Loc{
    int y, x, isBreak;
    Loc(int _y, int _x): y(_y), x(_x) {}
};

bool isRange(int y, int x) {
	return y < n && y >= 0 && x < m && x >= 0;
}

int getResult(){
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 0){
                return -1;
            }
            result = max(result, arr[i][j]);
        }
    }
    return result - 1;
}

int traverse(){
    queue<Loc> Queue;
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 1){
                Queue.push(Loc(i, j));
                cnt++;
            }
        }
    }
    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        if(cnt == totalTomatoes){
            return getResult();
        }
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(isRange(nextY, nextX) && arr[nextY][nextX] == 0){
                arr[nextY][nextX] = arr[cur.y][cur.x] + 1;
                Queue.push(Loc(nextY, nextX));
                cnt++;
            }
        }
    }
    return -1;
}

int main(){
    cin >> m >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
            if(arr[i][j] != -1){
                totalTomatoes++;
            }
        }
    }
    cout << traverse() << '\n';
    return 0;
}