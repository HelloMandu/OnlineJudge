#include<bits/stdc++.h>
using namespace std;

char arr[51][51];
int result = 1;
int n;

void search(){
    for(int i = 0; i < n; i++){
        int cnt = 1;
        for(int j = 1; j < n; j++){
            if(arr[i][j - 1] == arr[i][j]){
                cnt++;
                result = max(result, cnt);
            } else{
                cnt = 1;
            }
        }
    }

    for(int j = 0; j < n; j++){
        int cnt = 1;
        for(int i = 1; i < n; i++){
            if(arr[i - 1][j] == arr[i][j]){
                cnt++;
                result = max(result, cnt);
            } else{
                cnt = 1;
            }
        }
    }
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j + 1 < n){
                swap(arr[i][j], arr[i][j + 1]);
                search();
                swap(arr[i][j], arr[i][j + 1]);

            }
            if(i + 1 < n){
                swap(arr[i + 1][j], arr[i][j]);
                search();
                swap(arr[i + 1][j], arr[i][j]);
            }
        }
    }
    cout << result;
    return 0;
}