#include<bits/stdc++.h>
using namespace std;

int n;
int arr[101][101];
bool isVisit[101][101];
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int maxHeight = 0;
int minHeight = 987654321;

bool isRange(int y, int x){
    return y < n && y >= 0 && x < n && x >= 0;
}

void traverse(int y, int x, int height){
    isVisit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(isRange(nextY, nextX) && !isVisit[nextY][nextX] && arr[nextY][nextX] > height){
            traverse(nextY, nextX, height);
        }     
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            maxHeight = max(maxHeight, arr[i][j]);
            minHeight = min(minHeight, arr[i][j]);
        }
    }
    int result = 1;
    for(int i = minHeight; i < maxHeight; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                if(arr[j][k] > i && !isVisit[j][k]){
                    cnt++;
                    traverse(j, k, i);
                }
            }
        }
        result = max(result, cnt);
        memset(isVisit, false, sizeof(isVisit));
    }
    cout << result;
    return 0;
}