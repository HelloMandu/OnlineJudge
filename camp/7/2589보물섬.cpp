#include<bits/stdc++.h>
using namespace std;

int n, m;
char arr[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < m;
}

int bfs(pair<int, int> root){
    queue<pair<int, int> > Queue;
    Queue.push(root);
    int isVisit[51][51];
    memset(isVisit, 0, sizeof(isVisit));
    int result = 0;
    isVisit[root.first][root.second] = 1;
    while(!Queue.empty()){
        pair<int, int> cur = Queue.front(); Queue.pop();
        result = max(result, isVisit[cur.first][cur.second]);
        for(int i = 0; i < 4; i++){
            int ny = cur.first + dy[i];
            int nx = cur.second + dx[i];
            if(isRange(ny, nx) && !isVisit[ny][nx] && arr[ny][nx] == 'L'){
                isVisit[ny][nx] = isVisit[cur.first][cur.second] + 1;
                Queue.push(make_pair(ny, nx));
            }
        }
    }
    return result - 1;
}

int solution(){
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j] == 'L'){
                result = max(result, bfs(make_pair(i, j)));
            }
        }
    }
    return result;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << solution();
    return 0;
}