#include<bits/stdc++.h>
using namespace std;
int n, m;
int arr[10001];

bool isPossible(int mid){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += min(mid, arr[i]);
    }
    return sum <= m;
}

int main(){
    cin >> n;
    int left = 1;
    int right = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        right = max(right, arr[i]);
    }
    cin >> m;
    int result = 0;
    while(left <= right){
        int mid = (left + right) / 2;
        if(isPossible(mid)){
            left = mid + 1;
            result = mid;
        } else{
            right = mid - 1;
        }
    }
    cout << result;
    return 0;
}