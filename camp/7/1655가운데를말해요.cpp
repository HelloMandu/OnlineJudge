#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    priority_queue<int> maxHeap, minHeap;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        maxHeap.size() == minHeap.size() ? maxHeap.push(num) : minHeap.push(num * -1);

        while(!minHeap.empty() && maxHeap.top() > minHeap.top() * -1){
            int a = maxHeap.top(); maxHeap.pop();
            int b = minHeap.top() * -1; minHeap.pop();
            maxHeap.push(b);
            minHeap.push(a * -1);
        }
        cout << maxHeap.top() << '\n';
    }

}