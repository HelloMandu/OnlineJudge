#include<bits/stdc++.h>
using namespace std;

int n, m;
char arr[1001][1001];
int isVisit[1001][1001][2];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Loc{
    int y, x, isBreak;
    Loc(int _y, int _x, int _isBreak): y(_y), x(_x), isBreak(_isBreak) {}
};

bool isRange(int y, int x) {
	return y < n && y >= 0 && x < m && x >= 0;
}

int traverse(){
    queue<Loc> Queue;
    Queue.push(Loc(0, 0, 0));
    isVisit[0][0][0] = 1;
    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        if(cur.y == n - 1 && cur.x == m - 1){
            return isVisit[cur.y][cur.x][cur.isBreak];
        }
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            int isBreak = cur.isBreak;
            if(!isRange(nextY, nextX) || isVisit[nextY][nextX][isBreak]){
                continue;
            } else if(arr[nextY][nextX] == '1'){
                if(!isBreak){
                    Queue.push(Loc(nextY, nextX, 1));
                    isVisit[nextY][nextX][1] = isVisit[cur.y][cur.x][0] + 1;
                }
            } else{
                Queue.push(Loc(nextY, nextX, isBreak));
                isVisit[nextY][nextX][isBreak] = isVisit[cur.y][cur.x][isBreak] + 1;
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << traverse();
    return 0;
}