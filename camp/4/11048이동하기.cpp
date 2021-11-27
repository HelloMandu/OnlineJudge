#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[1001][1001];
int cache[1001][1001];
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cache[0][0] = arr[0][0];
    for(int i = 1; i < n; i++){
        cache[i][0] = cache[i - 1][0] + arr[i][0];
    }
    for(int i = 1; i < m; i++){
        cache[0][i] = cache[0][i - 1] + arr[0][i];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            cache[i][j] = max(max(cache[i - 1][j], cache[i][j - 1]), cache[i - 1][j - 1]) + arr[i][j];
        }
    }
    cout << cache[n - 1][m - 1];
    return 0;
}