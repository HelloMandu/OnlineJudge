#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

vector<vector<int> > graph;
int types[20001];

int getType(int type){
    return type == 0 ? 1 : 0;
}

bool bfs(int n){
    queue<int> Queue;
    Queue.push(n);
    types[n] = 1;
    while(!Queue.empty()){
        int cur = Queue.front(); Queue.pop();
        for(int i = 0; i < graph[cur].size(); i++){
            int next = graph[cur][i];
            if(types[next] == -1){
                types[next] = getType(types[cur]);
                Queue.push(next);
            }
            else if(types[next] == types[cur]){
                return false;
            }
        }
    }
    return true;
}


bool solution(){
    for(int i = 1; i < graph.size(); i++){
        if(types[i] == -1){
           if(!bfs(i)){
               return false;
           }
        }
    }
    return true;
}

int main(){
    int testcase;
    cin >> testcase;
    while(testcase--){
        memset(types, -1, sizeof(types));
        int v, e;
        cin >> v >> e;
        graph.resize(v + 1);
        while(e--){
            int v1, v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        if(solution()){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
        graph.clear();
    }
    return 0;
}