#include<bits/stdc++.h>
using namespace std;

int n, t, g;
int isVisit[100000];

int getDigit(int n){
    int result = 1;
    while(n){
        result *= 10;
        n /= 10;
    }
    result /= 10;
    return result;
}

int traverse(){
    queue<int> Queue;
    Queue.push(n);
    isVisit[n] = 0;
    while(!Queue.empty()){
        int cur = Queue.front(); Queue.pop();
        if(isVisit[cur] > t){
            return -1;
        }
        if(cur == g){
            return isVisit[cur];
        }
        int a = cur + 1;
        int b = cur * 2;
        if(a <= 99999){
            if(isVisit[a] == -1){
                Queue.push(a);
                isVisit[a] = isVisit[cur] + 1;
            }
        }
        if(b <= 99999){
            b -= getDigit(b);
            if(isVisit[b] == -1){
                Queue.push(b);
                isVisit[b] = isVisit[cur] + 1;
            }
        }
    }   
    return -1;
}

int main(){
    memset(isVisit, -1, sizeof(isVisit));
    cin >> n >> t >> g;
    int result = traverse();
    if(result != -1){
        cout << result;
    } else{
        cout << "ANG";
    }
    return 0;
}