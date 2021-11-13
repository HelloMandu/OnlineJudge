#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int, int> arr[1001];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n);

    int maxIndex = 0;
    for(int i = 0; i < n; i++){
        if(arr[maxIndex].second < arr[i].second){
            maxIndex = i;
        }
    }

    int result = 0;
    stack<int> Stack1;
    int cur = 0;
    Stack1.push(arr[cur++].second);
    for(int i = arr[0].first; i < arr[maxIndex].first; i++){
        if(i == arr[cur].first){
            if(arr[cur].second > Stack1.top()){
                Stack1.push(arr[cur].second);
            }
            cur++;
        }
        result += Stack1.top();
    }

    stack<int> Stack2;
    cur = n - 1;
    Stack2.push(arr[cur--].second);
    for(int i = arr[n - 1].first; i >= arr[maxIndex].first; i--){
        if(i == arr[cur].first){
            if(arr[cur].second > Stack2.top()){
                Stack2.push(arr[cur].second);
            }
            cur--;
        }
        result += Stack2.top();
    }
    cout << result;
    return 0;
}