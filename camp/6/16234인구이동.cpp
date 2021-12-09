#include<bits/stdc++.h>
using namespace std;

int n, l, r;
int arr[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
bool isVisit[51][51];

bool isRange(int y, int x){
    return y < n && y >= 0 && x < n && x >= 0;
}

bool isOpen(int a, int b){
    int diff = abs(a - b);
    return diff >= l && diff <= r;
}

bool bfs(int y, int x){
    queue<pair<int, int> > Queue;
    queue<pair<int, int> > connected;
    Queue.push(make_pair(y, x));
    connected.push(make_pair(y, x));
    isVisit[y][x] = true;
    int sum = 0;
    bool flag = false;
    while(!Queue.empty()){
        pair<int, int> cur = Queue.front(); Queue.pop();
        sum += arr[cur.first][cur.second];
        for(int k = 0; k < 4; k++){
            int nextY = cur.first + dy[k];
            int nextX = cur.second + dx[k];
            if(isRange(nextY, nextX) && !isVisit[nextY][nextX] && isOpen(arr[cur.first][cur.second], arr[nextY][nextX])){
                isVisit[nextY][nextX] = true;
                Queue.push(make_pair(nextY, nextX));
                connected.push(make_pair(nextY, nextX));
                flag = true;
            }
        }
    }
    if(!flag){
        return false;
    }
    // cout << connected.size() << '\n';
    int avg = (int)floor(sum / connected.size());
    while(!connected.empty()){
        pair<int, int> cur = connected.front(); connected.pop();
        arr[cur.first][cur.second] = avg;
    }
    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << arr[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // cout << '\n';
    return flag;
}

int main(){
    cin >> n >> l >> r;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    int result = 0;
    while(true){
        memset(isVisit, false, sizeof(isVisit));
        bool flag = false;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(isVisit[i][j]) {
                    continue;
                }
                if(bfs(i, j)){
                    flag = true;
                }
            }
        }
        if(!flag){
            break;
        }
        result++;
    }
    cout << result;
    return 0;
}