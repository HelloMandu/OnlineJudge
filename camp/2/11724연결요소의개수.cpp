#include<bits/stdc++.h>
using namespace std;

bool isVisit[1001];
vector<vector<int> > graph;

void traverse(int n){
    isVisit[n] = true;
    for(int i = 0; i < graph[n].size(); i++){
        int next = graph[n][i];
        if(!isVisit[next]){
            traverse(next);
        }
    }
}   

int main(){
    int v, e;
    cin >> v >> e;
    graph.resize(v + 1);
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int result = 0;
    for(int i = 1; i <= v; i++){
        if(!isVisit[i]){
            result++;
            traverse(i);
       }
    }
    cout << result;
    return 0;
}