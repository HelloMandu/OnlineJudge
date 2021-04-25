#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
#define MAX 100001
using namespace std;

int n, k;
int parents[MAX];
queue<int> Queue;

void bfs(){
    Queue.push(n);
    memset(parents, -1, sizeof(parents));
    parents[n] = n;
    while(!Queue.empty()){
        int front = Queue.front(); Queue.pop();
        if(front == k){
            vector<int> result;
            while(front != n){
                result.push_back(front);
                front = parents[front];
            }
            result.push_back(n);
            cout << result.size() - 1 << '\n';
            for(int i = result.size() - 1; i >= 0; i--){
                cout << result[i] << ' ';
            }
            return;
        }
        if(front * 2 < MAX && parents[front * 2] == -1){
            parents[front * 2] = front;
            Queue.push(front * 2);
        }
        if(front + 1 < MAX && parents[front + 1] == -1){
            parents[front + 1] = front;
            Queue.push(front + 1);
        }
        if(front - 1 >= 0 && parents[front - 1] == -1){
            parents[front - 1] = front;
            Queue.push(front - 1);
        }
    }
}

int main(){
    cin >> n >> k;
    bfs();
    return 0;
}