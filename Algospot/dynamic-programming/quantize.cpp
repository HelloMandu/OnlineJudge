#include<bits/stdc++.h>
using namespace std;

int n, parts;
int arr[101];
int cache[101][11];

int getErrorSquared(int number, int begin, int end){
    int result = 0;
    for(int i = begin; i <= end; i++){
        int diff = arr[i] - number;
        result += diff * diff;
    }
    return result;
}

int getMinimum(int begin, int end){
    int cur = arr[begin];
    int result = 987654321;
    while(cur <= arr[end]){
        result = min(result, getErrorSquared(cur, begin, end));
        cur++;
    }
    return result;
}

int quantize(int begin, int parts){
    if(begin == n){
        return 0;
    } else if(parts == 0){
        return 987654321;
    }
    int& ret = cache[begin][parts];
    if(ret != -1){
        return ret;
    }
    ret = 987654321;
    for(int i = begin + 1; i <= n; i++){
        ret = min(ret, getMinimum(begin, i - 1) + quantize(i, parts - 1));
    }
    return ret;
}

int main(){
    freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        cin >> n >> parts;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        cout << quantize(0, parts) << '\n';
    }

    return 0;
}