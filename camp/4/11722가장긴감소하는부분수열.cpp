#include<bits/stdc++.h>
using namespace std;
int n;
int arr[1001];
int cache[1001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] < arr[j]){
                cache[i] = max(cache[i], cache[j]);
            }
        }
        cache[i]++;
        result = max(cache[i], result);
    }
    cout << result;
    return 0;
}