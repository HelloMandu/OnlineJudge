#include<bits/stdc++.h>
using namespace std;

int n;
int graph[17][17];
int cache[17][1<<17];
const int INF = 987654321;

int solve(int cur, int visited){
    int &ret = cache[cur][visited];
    if(ret != -1){
        return ret;
    }
    if(visited == ((1 << n) - 1)){
        return graph[cur][0] ? graph[cur][0] : INF;
    }
    ret = INF;
    for(int i = 0; i < n; i++){
        if(!graph[cur][i]){
            continue;
        } else if(visited & (1 << i)){
            continue;
        }
        ret = min(ret , solve(i, visited | (1 << i)) + graph[cur][i]);
    }
    return ret;
}

int main(){
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
    cout << solve(0, 1);
    return 0;
}