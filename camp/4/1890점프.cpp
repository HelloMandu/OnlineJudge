#include<bits/stdc++.h>
using namespace std;
int n;
int arr[101][101];
long long cache[101][101];

long long solution(int y = 0, int x = 0){
    if(y >= n || x >= n){
        return 0;
    } else if(y == n - 1 && x == n - 1){
        return 1;
    }
    long long &ret = cache[y][x];
    if(ret != -1){
        return ret;
    }
    ret = 0;
    return ret = solution(y + arr[y][x], x) + solution(y, x + arr[y][x]);
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    cout << solution();
    return 0;
}