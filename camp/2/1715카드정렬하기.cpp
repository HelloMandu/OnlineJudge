#include<bits/stdc++.h>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int> > heap;
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        heap.push(num);
    }
    int result = 0;
    while(heap.size() > 1){
        int a = heap.top(); heap.pop();
        int b = heap.top(); heap.pop();
        result += a + b;
        heap.push(a + b);
    }
    cout << result;
    return 0;
}