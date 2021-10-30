#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, range;
    int arr[1001];
    int result = 1;
    cin >> n >> range;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    int begin = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] - begin >= range){
            begin = arr[i];
            result++;
        }
    }
    cout << result;
    return 0;
}