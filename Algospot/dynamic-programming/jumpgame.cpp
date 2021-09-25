#include<bits/stdc++.h>
using namespace std;

int cache[101][101];
int grid[101][101];
int n;

bool canReach(int y, int x){
    if(y == n - 1 && x == n - 1){
        return true;
    } else if(y >= n || x >= n){
        return false;
    }
    int& ret = cache[y][x];
    if(ret != -1){
        return ret;
    }
    return ret = canReach(y + grid[y][x], x) || canReach(y, x + grid[y][x]);
}

int main(){
    freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        cin >> n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> grid[i][j];
            }
        }
        cout << (canReach(0, 0) ? "YES\n" : "NO\n");
    }

    return 0;
}