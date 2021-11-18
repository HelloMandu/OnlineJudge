#include<bits/stdc++.h>
using namespace std;

bool arr[101][101];
int n, m, k;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int result = 0;

bool isRange(int y, int x){
    return y < n && y >= 0 && x < m && x >= 0;
}

int traverse(int y, int x){
    int count = 1;
    arr[y][x] = false;
    for(int i = 0; i < 4; i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(isRange(nextY, nextX) && arr[nextY][nextX]){
            count += traverse(nextY, nextX);
        }     
    }
    return count;
}

int main(){
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int v, e;
        cin >> v >> e;
        arr[v - 1][e - 1] = true;
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(arr[i][j]){
                result = max(result, traverse(i, j));
            }
        }
    }
    cout << result;
    return 0;
}