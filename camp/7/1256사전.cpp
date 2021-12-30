#include<bits/stdc++.h>
using namespace std;

int cache[101][101];

long long fac(long long n){
    long long result = 1;
    while(n--){
        if(n > 0)
            result *= n;
    }
    return result;
}

long long comb(int n, int m){
    return fac(n) / fac(m) * fac(n - m);
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int len = n + m;
    int arr[201];
    for(int i = 0; i < len; i++){
        if(i < n){
            arr[i] = 0;
        } else{
            arr[i] = 1;
        }
    }
    if(comb(len, n) < k){
        cout << -1;
        return 0;
    }
    int cnt = 0;
    do{
        cnt++;
        if(cnt == k){
            for(int i = 0; i < len; i++){
                cout << (arr[i] ? 'z' : 'a');
            }
            return 0;
        }
    }while(next_permutation(arr, arr + len));
    cout << -1;
    return 0;
}