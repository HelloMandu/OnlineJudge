#include<bits/stdc++.h>
using namespace std;

int n, m;
bool hasFriends[11];
bool pairs[11][11];

int getCountPairs(){
    int me = -1;
    for(int i = 0; i < n; i++){
        if(!hasFriends[i]){
            me = i;
            break;
        }
    }
    if(me == -1){
        return 1; 
    }
    int ret = 0;
    for(int you = me + 1; you < n; you++){
        if(!hasFriends[you] && pairs[me][you]){
            hasFriends[me] = hasFriends[you] = true;
            ret += getCountPairs();
            hasFriends[me] = hasFriends[you] = false;
        }
    }
    return ret;
}

int main() {
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> n >> m;
        memset(pairs, false, sizeof(pairs));
        memset(hasFriends, false, sizeof(hasFriends));
        for(int i = 0; i < m; i++){
            int first, second;
            cin >> first >> second;
            pairs[first][second] = true;
            pairs[second][first] = true;
        }
        cout << getCountPairs() << '\n';
    }
    
    return 0;
}
