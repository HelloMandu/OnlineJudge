#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<string> Set;
    cin >> n;
    while(n--){
        string name, type;
        cin >> name >> type;
        if(type == "enter"){
            Set.insert(name);
        } else{
            Set.erase(name);
        }
    }
    for(set<string>::reverse_iterator it = Set.rbegin(); it != Set.rend(); it++){
        cout << *it << '\n';
    }
    return 0;
}