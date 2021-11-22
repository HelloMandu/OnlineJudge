#include<bits/stdc++.h>
using namespace std;

int f, s, g, u, d;
int isVisit[1000001];

int traverse(){
    queue<int> Queue;
    Queue.push(s);
    isVisit[s] = 0;
    while(!Queue.empty()){
        int cur = Queue.front(); Queue.pop();
        if(cur == g){
            return isVisit[cur];
        }
        int up = cur + u;
        int down = cur - d;
        if(up <= f && isVisit[up] == -1){
            isVisit[up] = isVisit[cur] + 1;
            Queue.push(up);
        }
        if(down >= 1 && isVisit[down] == -1){
            isVisit[down] = isVisit[cur] + 1;
            Queue.push(down);
        }
    }
    return -1;
}

int main(){
    cin >> f >> s >> g >> u >> d;
    memset(isVisit, -1, sizeof(isVisit));
    int result = traverse();
    if(result != -1){
        cout << result;
    } else{
        cout << "use the stairs";
    }
    return 0;
}