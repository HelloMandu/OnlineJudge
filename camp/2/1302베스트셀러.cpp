#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<string, int> m;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        if(m.find(str) != m.end()){
            m.find(str)->second++;
        } else{
            m.insert(make_pair(str, 1));
        }
    }
    string result = "";
    int maxNum = 0;
    for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++) { 
        if(maxNum < iter->second){
            result = iter->first;
            maxNum = iter->second;
        }
    } 
    cout << result;
    return 0;
}