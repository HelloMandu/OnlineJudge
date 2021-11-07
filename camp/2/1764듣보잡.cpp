#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    set<string> Set;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        Set.insert(str);
    }
    vector<string> result;
    for(int i = 0; i < m; i++){
        string str;
        cin >> str;
        if(Set.find(str) != Set.end()){
            result.push_back(str);
        }
    }
    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << '\n';
    }
    return 0;
}