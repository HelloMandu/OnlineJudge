#include<bits/stdc++.h>
using namespace std;

int n, l;
int arr1[101][101];
int arr2[101][101];

bool check(vector<int> arr){
    vector<bool> isVisit;
    for(int i = 0; i < arr.size(); i++){
        isVisit.push_back(false);
    }
    for(int i = 0; i < n - 1; i++){
        int diff = arr[i + 1] - arr[i];
        if(abs(diff) > 1){
            return false;
        } else if(diff == 1){ // 오름
            int load = i + 1 - l;
            if(load < 0){
                return false;
            }
            for(int j = load; j <= i; j++){
                if(isVisit[j]){
                    return false;
                }
                if(arr[j] != arr[i]){
                    return false;
                }
                isVisit[j] = true;
            }
        } else if(diff == -1){ // 내림
            int load = i + l;
            if(load >= n){
                return false;
            }
            for(int j = i + 1; j <= load; j++){
                if(isVisit[j]){
                    return false;
                }
                if(arr[j] != arr[i + 1]){
                    return false;
                }
                isVisit[j] = true;
            }
        }
    }
    
    return true;
}

bool canPass(int _arr[]){
    vector<int> arr;
    for(int i = 0; i < n; i++){
        arr.push_back(_arr[i]);
    }
    return check(arr);
}

int main(){
    cin >> n >> l;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr1[i][j];
            arr2[j][i] = arr1[i][j];
        }
    }
    int result = 0;
    for(int i = 0; i < n; i++){
        result += canPass(arr1[i]);
    }
    for(int i = 0; i < n; i++){
        result += canPass(arr2[i]);
    }
    cout << result;
    return 0;
}