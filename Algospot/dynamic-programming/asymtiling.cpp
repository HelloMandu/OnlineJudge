#include<bits/stdc++.h>
using namespace std;

int cache[101];
const int MOD = 1000000007;

int tiling(int n){
    if(n <= 1){
        return 1;
    }
    int& ret = cache[n];
    if(ret != -1){
        return ret;
    }
    return ret = (tiling(n - 1) + tiling(n - 2)) % MOD;
}

int asymtiling(int n){
    if(n % 2 == 1){
        return (tiling(n) - tiling(n / 2) + MOD) % MOD;
    }
    int ret = tiling(n);
    ret = (ret - tiling(n / 2) + MOD) % MOD;
    ret = (ret - tiling(n / 2 - 1) + MOD) % MOD;
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
        cout << asymtiling(n) << '\n';
    }
    return 0;
}