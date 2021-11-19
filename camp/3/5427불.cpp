#include<bits/stdc++.h>
using namespace std;

struct Loc{
    int y, x;
    Loc(int _y, int _x): y(_y), x(_x) {}
};

int w, h;
char arr[1001][1001];
int fire[1001][1001];
int moving[1001][1001];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
queue<Loc> fireQueue, moveQueue;
vector<Loc> fires;

bool isRange(int y, int x) {
	return y < h && y >= 0 && x < w && x >= 0;
}

void fireTraverse(){
    for(int i = 0; i < fires.size(); i++){
        fireQueue.push(fires[i]);
        fire[fires[i].y][fires[i].x] = 0;
    }
    while(!fireQueue.empty()){
        Loc cur = fireQueue.front(); fireQueue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(isRange(nextY, nextX) && arr[nextY][nextX] != '#' && fire[nextY][nextX] == -1){
                fire[nextY][nextX] = fire[cur.y][cur.x] + 1;
                fireQueue.push(Loc(nextY, nextX));
            }
        }
    }
}

int moveTraverse(){
    moving[moveQueue.front().y][moveQueue.front().x] = 0;
    while(!moveQueue.empty()){
        Loc cur = moveQueue.front(); moveQueue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.y + dy[i];
            int nextX = cur.x + dx[i];
            if(!isRange(nextY, nextX)){
                return moving[cur.y][cur.x] + 1;
            }
            if(arr[nextY][nextX] == '.' && moving[nextY][nextX] == -1 && (fire[nextY][nextX] == -1 || fire[nextY][nextX] > moving[cur.y][cur.x] + 1)){
                moving[nextY][nextX] = moving[cur.y][cur.x] + 1;
                moveQueue.push(Loc(nextY, nextX));
            }
        }
    }
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        fires.clear();
        while(!fireQueue.empty()){
            fireQueue.pop();
        }
        while(!moveQueue.empty()){
            moveQueue.pop();
        }
        memset(fire, -1, sizeof(fire));
        memset(moving, -1, sizeof(moving));
        cin >> w >> h;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(arr[i][j] == '@'){
                    moveQueue.push(Loc(i, j));
                } else if(arr[i][j] == '*'){
                    fires.push_back(Loc(i, j));
                }
            }
        }
        fireTraverse();
        int result = moveTraverse();
        if(result > 0){
            cout << result << '\n';
        } else{
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}