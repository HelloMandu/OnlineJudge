#include<bits/stdc++.h>
using namespace std;

string str;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool isRange(int y, int x){
    return y < 3 && y >= 0 && x < 3 && x >= 0;
}

int traverse(){
    queue<pair<string, int> > Queue;
    set<string> Set;
    Queue.push(make_pair(str, 0));
    Set.insert(str);
    while(!Queue.empty()){
        pair<string, int> cur = Queue.front(); Queue.pop();
        if(cur.first == "123456780"){
            return cur.second;
        }
        int zeroIdx = cur.first.find('0');
        int y = zeroIdx / 3, x = zeroIdx % 3;
        for(int i = 0; i < 4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if(isRange(nextY, nextX)){
                string temp = cur.first;
                swap(temp[y * 3 + x], temp[nextY * 3 + nextX]);
                if(Set.find(temp) == Set.end()){
                    Queue.push(make_pair(temp, cur.second + 1));
                    Set.insert(temp);
                }
            }
        }
    }
    return -1;
}

int main(){
    for(int i = 0; i < 9; i++){
        char c;
        cin >> c;
        str += c;
    }
    cout << traverse();
    return 0;
}