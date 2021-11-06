#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, money;
    int arr[11];
    int result = 0;
    cin >> n >> money;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int idx = n - 1;
    while(money){
        result += money / arr[idx];
        money %= arr[idx];
        idx--;
    }
    cout << result;
    return 0;
}