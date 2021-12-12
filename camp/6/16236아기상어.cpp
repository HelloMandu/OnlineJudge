#include<bits/stdc++.h>
using namespace std;

int n;
int arr[21][21];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
pair<int, int> shark;
int sharkSize = 2;
int result = 0;

bool isRange(int y, int x){
    return y < n && y >= 0 && x < n && x >= 0;
}

int solution(){
    int isVisit[21][21];
    memset(isVisit, 0, sizeof(isVisit));
    queue<pair<int, int> > Queue;
    Queue.push(shark);
    while(!Queue.empty()){
        pair<int, int> cur = Queue.front(); Queue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = cur.first + dy[i];
            int nextX = cur.second + dx[i];
            if(isRange(nextY, nextX) && !isVisit[nextY][nextX] && arr[nextY][nextX] <= sharkSize){
                Queue.push(make_pair(nextY, nextX));
                isVisit[nextY][nextX] = isVisit[cur.first][cur.second] + 1;
                
            }
        }
    }
    int INF = 987654321;
    int result = INF;
    pair<int, int> loc;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isVisit[i][j] && arr[i][j] && arr[i][j] < sharkSize && result > isVisit[i][j]){
                shark = loc = make_pair(i, j);
                result = isVisit[i][j];
            }
        }
    }
    if(result == INF){
        return -1;
    }
    arr[loc.first][loc.second] = 0;
    return result;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
            if(arr[i][j] == 9){
                shark = make_pair(i, j);
                arr[i][j] = 0;
            }
        }
    }
    int eat = sharkSize;
    while(true){
        int time = solution();
        if(time == -1){
            break;
        }
        result += time;
        eat--;
        if(eat == 0){
            sharkSize++;
            eat = sharkSize;
        }
    }
    cout << result;
    return 0;
}