#include<bits/stdc++.h>
using namespace std;

int n, s;
int arr[21];
int result = 0;

void solution(int cur = 0, int sum = 0){
    if(cur == n){
        return;
    } else if(sum + arr[cur] == s){
        result++;
    } 
    solution(cur + 1, sum);
    solution(cur + 1, sum + arr[cur]);
}

int main(){
    cin >> n >> s;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    solution();
    cout << result;
    return 0;
}
