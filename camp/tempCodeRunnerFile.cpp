#include<bits/stdc++.h>
using namespace std;

int n, s;
int arr[21];
int result = 0;

void solution(int cur = -1, int sum = 0){
    if(sum == s){
        result++;
    } 
    for(int i = cur + 1; i < n; i++){
        solution(i, sum + arr[i]);
    }
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
