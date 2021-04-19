#include<iostream>
#include<deque>
using namespace std;

deque<int> Deque;

int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        Deque.push_back(i);
    }
    int result = 0;
    while(m--){
        int num;
        cin >> num;
        int loc = 0;
        for(int i = 0; i < Deque.size(); i++){
            if(num == Deque[i]){
                loc = i;
                break;
            }
        }
        if(loc < (Deque.size() + 1) / 2){
            while(true){
                if(Deque.front() == num){
                    Deque.pop_front();
                    break;
                }
                Deque.push_back(Deque.front());
                Deque.pop_front();
                result++;
            }
        } else{
            while(true){
                if(Deque.front() == num){
                    Deque.pop_front();
                    break;
                }
                Deque.push_front(Deque.back());
                Deque.pop_back();
                result++;
            }
        }
    }
    cout << result << '\n';
    return 0;
}