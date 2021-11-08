#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> heap;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        heap.push(num * -1);
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j < n; j++){
            int num;
            cin >> num;
            heap.push(num * -1);
        }
        for(int j = 0; j < n; j++){
            heap.pop();
        }
    }
    cout << heap.top() * -1;
    return 0;
}