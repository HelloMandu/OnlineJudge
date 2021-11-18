#include<bits/stdc++.h>
using namespace std;

char arr[101][101];
bool isVisit[101][101];
int n;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int result = 0;

bool isRange(int y, int x){
    return y < n && y >= 0 && x < n && x >= 0;
}

void traverse(int y, int x, char c){
    isVisit[y][x] = true;
    for(int i = 0; i < 4; i++){
        int nextY = y + dy[i];
        int nextX = x + dx[i];
        if(isRange(nextY, nextX) && !isVisit[nextY][nextX] && arr[nextY][nextX] == c){
            traverse(nextY, nextX, c);
        }     
    }
}
int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isVisit[i][j]){
                result++;
                traverse(i, j, arr[i][j]);
            }
        }
    }
    cout << result << ' ';
    result = 0;
    memset(isVisit, false, sizeof(isVisit));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(arr[i][j] == 'G'){
                arr[i][j] = 'R';
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!isVisit[i][j]){
                result++;
                traverse(i, j, arr[i][j]);
            }
        }
    }
    cout << result;
    return 0;
}