#include<bits/stdc++.h>
using namespace std;

int cache[101][101];
const int MOD = 10000000;

int poly(int n, int first){
    if(n == first){
        return 1;
    }
    int& ret = cache[n][first];
    if(ret != -1){
        return ret;
    }
    ret = 0;
    for(int next = 1; next <= n - first; next++){
        int add = (poly(n - first, next) * (first + next - 1)) % MOD;
        ret = (ret + add) % MOD;
    }
    return ret;
}

int main(){
    freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    memset(cache, -1, sizeof(cache));
    while(t--){
        int n;
        cin >> n;
        int result = 0;
        for(int i = 1; i <= n; i++){
            result = (result + poly(n, i)) % MOD;
        }
        cout << result << '\n';
    }
    return 0;
}