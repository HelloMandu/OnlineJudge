#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int t;
    cin >> t;
    queue<int> Queue;
    while(t--){
        string str; 
        cin >> str;
        if(str == "push"){
            int n;
            cin >> n;
            Queue.push(n);
        } else if(str == "front"){
            cout << (Queue.empty() ? -1 : Queue.front()) << '\n';
        } else if(str == "back"){
            cout << (Queue.empty() ? -1 : Queue.back()) << '\n';
        } else if(str == "pop"){
            if(Queue.empty()){
                cout << -1 << '\n';
            } else {
                cout << Queue.front() << '\n';
                Queue.pop();
            }
            
        } else if(str == "size"){
            cout << Queue.size() << '\n';
        } else if(str == "empty"){
            cout << (Queue.empty() ? 1 : 0) << '\n';
        }
    }
    return 0;
}