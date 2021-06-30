#include<iostream>
#include<stack>
#include<cstring>
using namespace std;

int f[1000001];
int arr[1000001];
int result[1000001];

int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        f[arr[i]]++;
    }
    stack<int> Stack;
    memset(result, -1, sizeof(result));
    for(int i = 0; i < n; i++){
        while(!Stack.empty() && f[arr[Stack.top()]] < f[arr[i]]){
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