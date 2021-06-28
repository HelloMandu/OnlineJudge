#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int arr[1000001];
int result[1000001];

int main(){
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    memset(result, -1, sizeof(result));
    stack<int> Stack;
    for(int i = 0; i < n; i++){
        while(!Stack.empty() && arr[Stack.top()] < arr[i]){
            result[Stack.top()] = arr[i];
            Stack.pop();
        }
        Stack.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << result[i] << ' ';
    }
    return 0;
}