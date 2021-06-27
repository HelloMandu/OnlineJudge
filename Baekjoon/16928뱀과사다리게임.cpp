#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

map<int, int> SL;
bool isVisit[101];

bool isFinish(int cur){
    return cur == 100;
}

int getMinCount(){
    queue<pair<int, int> > Queue;
    Queue.push(pair<int, int>(1, 0));
    int result = 987654321;
    while(!Queue.empty()){
        pair<int, int> cur = Queue.front(); Queue.pop();
        if(isVisit[cur.first]){
            continue;
        }
        isVisit[cur.first] = true;
        if(isFinish(cur.first)){
            result = min(result, cur.second);
        }
        map<int, int>::iterator hasSL = SL.find(cur.first);
        if(hasSL != SL.end()){
            cur = pair<int, int>((*hasSL).second, cur.second);
        }
        for(int i = 0; i < 6; i++){
            int next = cur.first + i + 1;
            if(next <= 100){
                Queue.push(pair<int, int>(next, cur.second + 1));
            }
        }
    }
    return result;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n + m; i++){
        int s, e;
        cin >> s >> e;
        SL.insert(pair<int, int>(s, e));
    }
    cout << getMinCount();
    return 0;
}