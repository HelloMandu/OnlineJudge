#include<bits/stdc++.h>
using namespace std;

int n, m;
char arr[51][51];
int water[51][51];
int moving[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Loc{
    int y, x;
    Loc(int _y, int _x): y(_y), x(_x) {}
};

bool isRange(int y, int x) {
	return y < n && y >= 0 && x < m && x >= 0;
}

void waterTraverse(){
    queue<Loc> Queue;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            water[i][j] = INT_MAX;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == '*'){
                Queue.push(Loc(i, j));
                water[i][j] = 0;
            }
        }
    }

    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(isRange(nextY, nextX) && arr[nextY][nextX] == '.' && water[nextY][nextX] == INT_MAX){
                water[nextY][nextX] = water[cur.y][cur.x] + 1;
                Queue.push(Loc(nextY, nextX));
            }
        }
    }
}

int traverse(int y, int x){
    queue<Loc> Queue;
    Queue.push(Loc(y, x));
    moving[y][x] = 0;
    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(arr[nextY][nextX] == 'D'){
                return moving[cur.y][cur.x] + 1;
            }
            if(
                isRange(nextY, nextX) 
            && arr[nextY][nextX] != 'X' 
            && arr[nextY][nextX] != '*' 
            && moving[nextY][nextX] == -1 
            && water[nextY][nextX] > moving[cur.y][cur.x] + 1){
                moving[nextY][nextX] = moving[cur.y][cur.x] + 1;
                Queue.push(Loc(nextY, nextX));
            }
        }
    }
    return 0;
}

int main(){
    cin >> n >> m;
    memset(moving, -1, sizeof(moving));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    waterTraverse();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'S'){
                int result = traverse(i, j);
                if(result > 0){
                    cout << result;
                } else{
                    cout << "KAKTUS";
                }
                return 0;
            }
        }
    }
    return 0;
}