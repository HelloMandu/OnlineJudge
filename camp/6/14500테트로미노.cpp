#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[501][501];

int main(){
    cin >> n >> m;
    for(int i = 0 ; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    return 0;
}