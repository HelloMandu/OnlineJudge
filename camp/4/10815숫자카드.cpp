#include<bits/stdc++.h>
using namespace std;

int n, m;
set<int> Set;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        Set.insert(num);
    }
    cin >> m;
    while(m--){
        int num;
        cin >> num;
        cout << (Set.find(num) != Set.end() ? 1 : 0) << ' ';
    }
    return 0;
}