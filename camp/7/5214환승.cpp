#include<bits/stdc++.h>
using namespace std;

int n, k, m;
vector<vector<int> > graph;
int isVisit[101001];

int bfs(){
    queue<int> Queue;
    Queue.push(0);
    isVisit[0] = 1;
    while(!Queue.empty()){
        int cur = Queue.front(); Queue.pop();
        if(cur == n - 1){
            return (isVisit[cur] + 1) / 2;
        }
        for(int i = 0; i < graph[cur].size(); i++){
            if(!isVisit[graph[cur][i]]){
                isVisit[graph[cur][i]] = isVisit[cur] + 1;
                Queue.push(graph[cur][i]);
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> k >> m;
    graph.resize(n + m);
    for(int i = 0; i < m; i++){
        for(int j = 0; j < k; j++){
            int num;
            cin >> num;
            graph[num - 1].push_back(i + n);
            graph[i + n].push_back(num - 1);
        }
    }
    cout << bfs();
    return 0;
}