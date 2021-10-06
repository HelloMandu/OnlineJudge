#include<bits/stdc++.h>
using namespace std;

int n, d, p;
int graph[51][51];
int degree[51];
double cache[101][51];

void init(){
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < 51; j++){
            cache[i][j] = -1;
        }
    }
    memset(graph, 0, sizeof(graph));
    memset(degree, 0, sizeof(degree));
    cin >> n >> d >> p;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
            if(graph[i][j]){
                degree[i]++;
            }
        }
    }
}

double solution(int days, int vertex){
    if(days == 0){
        return vertex == p ? 1 : 0;
    }
    double& ret = cache[days][vertex];
    if(ret != -1){
        return ret;
    }
    ret = 0;
    for(int i = 0; i < n; i++){
        int next = graph[vertex][i];
        if(next){
            ret += solution(days - 1, i) / degree[i];
        }
    }
    return ret;
}

int main(){
    // freopen("../input.txt", "r", stdin);
    int testcase;
    cin >> testcase;
    while(testcase--){
        init();
        int t;
        cin >> t;
        while(t--){
            int v;
            cin >> v;
            cout.precision(8);
            cout << solution(d, v) << ' ';
        }
        cout << '\n';
    }
    return 0;
}