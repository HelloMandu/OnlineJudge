#include<bits/stdc++.h>
using namespace std;

bool cache[301];

int main(){
    int a, b, c, n;
    cin >> a >> b >> c >> n;
    cache[a] = cache[b] = cache[c] = true;
    for(int i = 1; i <= n; i++){
        if(cache[i]){
            cache[i + a] = true; 
            cache[i + b] = true; 
            cache[i + c] = true; 
        }
    }
    cout << cache[n];
    return 0;
}