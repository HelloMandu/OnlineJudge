#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];
int cnt = 1;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int isVisit[101][101];

bool isRange(int y, int x){
    return y < n && y >= 0 && x < n && x >= 0;
}

void dfs(int y, int x, int num){
    arr[y][x] = num;
    for(int i = 0; i < 4; i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(isRange(nextY, nextX) && arr[nextY][nextX] == -1){
            dfs(nextY, nextX, num);
        }
    }
}

void init(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == -1){
                dfs(i, j, cnt++);
            }
        }
    }
}

int bfs(int c){
    memset(isVisit, 0, sizeof(isVisit));
    queue<pair<int, int> > Queue;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == c){
                isVisit[i][j] = 1;
                Queue.push(make_pair(i, j));
            }
        }
    }
    // cout << c << '\n';
    while(!Queue.empty()){
        pair<int, int> cur = Queue.front(); Queue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.first + dy[i];
            int nextX = cur.second + dx[i];
            if(!isRange(nextY, nextX) || arr[nextY][nextX] == c){continue;}

            if(arr[nextY][nextX] > 0){
                return isVisit[cur.first][cur.second];
            }
            if(!isVisit[nextY][nextX]) {
                isVisit[nextY][nextX] = isVisit[cur.first][cur.second] + 1;
                Queue.push(make_pair(nextY, nextX));
            }
        }
    }
    return 987654231;
}

int solution(){
    int result = 987654321;
    while(--cnt > 0){
        result = min(result, bfs(cnt));
    }
    return result;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j]){
                arr[i][j] = -1;
            }
        }
    }
    init();
    cout << solution() - 1;
    return 0;
}