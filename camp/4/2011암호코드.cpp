#include<bits/stdc++.h>
using namespace std;

int cache[5001];
int arr[5001];

int main(){
    string str;
    cin >> str;
    int len = str.length();
    for(int i = 1; i <= len; i++){
        arr[i] = str[i - 1] - '0';
    }
    if(arr[1] == 0){
        cout << 0;
        return 0;
    }
    cache[0] = 1;
    for(int i = 1; i <= len; i++){
        if(arr[i] >= 1 && arr[i] <= 9){
            cache[i] = (cache[i] + cache[i - 1]) % 1000000;
        }
        int temp = arr[i - 1] * 10 + arr[i];
        if(temp >= 10 && temp <= 26){
            cache[i] = (cache[i] + cache[i - 2]) % 1000000;
        }
    }
    cout << cache[len];
    return 0;
}