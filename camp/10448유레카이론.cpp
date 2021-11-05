#include<bits/stdc++.h>
using namespace std;

vector<int> tri;

void init(){
    int n = 1;
    while((n * (n + 1) / 2) <= 1000){
        tri.push_back((n * (n + 1) / 2));
        n++;
    }
}

int isTri(int n){
    for(int i = 0; i < tri.size(); i++){
        for(int j = 0; j < tri.size(); j++){
            for(int k = 0; k < tri.size(); k++){
                if(tri[i] + tri[j] + tri[k] == n){
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main(){
    init();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << isTri(n) << '\n';
    }
    return 0;
}
