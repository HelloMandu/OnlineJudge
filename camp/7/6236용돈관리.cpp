#include<bits/stdc++.h>
using namespace std;

int n, m;
int arr[100001];

bool isPossible(int mid){
    int cnt = 1;
    int sum = mid;
    for(int i = 0; i < n; i++){
        if(mid < arr[i]){
            return false;
        } else if(sum - arr[i] < 0){
            sum = mid;
            cnt++;
        }
        sum -= arr[i];
    }
    return cnt <= m;
}

int main(){
    cin >> n >> m;
    int left = 0;
    int right =  0;  
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        left = max(left, arr[i]);
        right += arr[i];
    } 
    int ans = right;
    while(left <= right){
        int mid = (left + right) / 2;
        if(isPossible(mid)){
            ans = min(mid, ans);
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}