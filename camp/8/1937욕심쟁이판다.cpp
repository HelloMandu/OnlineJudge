#include<bits/stdc++.h>
using namespace std;

int n;
int arr[501][501];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
int isVisit[501][501];

bool isRange(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < n;
}

int dfs(pair<int, int> cur){
    int y = cur.first;
    int x = cur.second;
    if(isVisit[y][x]){
        return isVisit[y][x];
    }
    isVisit[y][x] = 1;
    for(int i = 0; i < 4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(isRange(ny, nx) && arr[y][x] < arr[ny][nx]){
            isVisit[y][x] = max(isVisit[y][x], dfs(make_pair(ny, nx)) + 1); 
        }
    }
    return isVisit[y][x];
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            result = max(result, dfs(make_pair(i, j)));
        }
    }
    cout << result;
    return 0;
}