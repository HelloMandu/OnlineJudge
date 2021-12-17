#include<bits/stdc++.h>
using namespace std;
long long arr[100001];
int n, m;

bool isPossible(long long mid){
    long long cnt = 0, sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + arr[i] > mid){
            sum = 0;
            cnt++;
        }
        sum += arr[i];
    }
    if(sum){
        cnt++;
    }
    return cnt <= m;
}

int main(){
    cin >> n >> m;
    long long left = 0, right = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        left = max(left, arr[i]);
        right += arr[i];
    }
    long long ans = right;
    while(left <= right){
        long long mid = (left + right) / 2;
        if(isPossible(mid)){
            ans = min(ans, mid);
            right = mid - 1;
        } else{
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}