#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > heap;

int main(){
    int n;
    cin >> n;
    while(n--){
        int num;
        cin >> num;
        if(num == 0){
            if(heap.empty()){
                cout << 0 << '\n';
            } else{
                cout << heap.top().second << '\n';
                heap.pop();
            }
        } else{
            heap.push(make_pair(abs(num), num ));
        }
    }
    return 0;
}