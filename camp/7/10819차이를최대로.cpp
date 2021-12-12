#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, arr[10];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int result = 0;
    do{
        int sum = 0;
        for(int i = 1; i < n; i++){
            sum += abs(arr[i] - arr[i - 1]);
        }
        result = max(result, sum);
    } while(next_permutation(arr, arr + n));
    cout << result;
}