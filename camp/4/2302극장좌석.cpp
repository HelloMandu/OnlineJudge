#include<bits/stdc++.h>
using namespace std;

int cache[41];
int main(){
    int n, m;
    cin >> n >> m;
    cache[0] = cache[1] = 1;
    for(int i = 2; i <= n; i++){
        cache[i] = cache[i - 1] + cache[i - 2];
    }
    int result  = 1;
    int prev = 0;
    while(m--){
        int num;
        cin >> num;
        result *= cache[num - prev - 1];
        prev = num;
    }
    result *= cache[n - prev];
    cout << result;
    return 0;
}