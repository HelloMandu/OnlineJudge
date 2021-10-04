#include<bits/stdc++.h>
using namespace std;

int path[101][101];
int cache[101][101];
int pathCnt[101][101];
int n;

int getTriPath(int y = 0, int x = 0){
    int& ret = cache[y][x];
    if(y == n - 1){
        return ret = path[y][x];
    } else if(ret != -1){
        return ret;
    }
    return ret = max(getTriPath(y + 1, x), getTriPath(y + 1, x + 1)) + path[y][x];
}

int getTriPathCnt(int y = 0, int x = 0){
    int& ret = pathCnt[y][x];
    if(y == n - 1){
        return ret = 1;
    } else if(ret){
        return ret;
    }
    int left = cache[y + 1][x];
    int right = cache[y + 1][x + 1];
    if(left >= right) {
        ret += getTriPathCnt(y + 1, x);
    }
    if(left <= right){
        ret += getTriPathCnt(y + 1, x + 1);
    }
    return ret;
}

int main(){
    freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        memset(pathCnt, 0, sizeof(pathCnt));
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i + 1; j++){
                cin >> path[i][j];
            }
        }
        getTriPath();
        cout << getTriPathCnt() << '\n';
    }

    return 0;
}