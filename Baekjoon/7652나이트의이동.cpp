#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

struct Loc{
    int y, x;
};

int map[301][301];
int n = 0;
int endY, endX;

int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool isRange(int y, int x){
    return y < n && y >= 0 && x < n && x >= 0;
}

int solution(int y, int x){
    queue<Loc> Queue;
    Queue.push({y, x});
    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        if(cur.y == endY && cur.x == endX){
            return map[cur.y][cur.x];
        }
        for(int i = 0; i < 8; i++){
            int nextY = cur.y + dy[i], nextX = cur.x + dx[i];
            if(isRange(nextY, nextX) && !map[nextY][nextX]){
                map[nextY][nextX] = map[cur.y][cur.x] + 1;
                Queue.push({nextY, nextX});
            }
        }
    }
    return -1;
}


int main(){
    int testcase;
    cin >> testcase;
    int startY, startX;
    while(testcase--){
        memset(map, 0, sizeof(map));
        cin >> n >> startY >> startX >> endY >> endX;
        cout << solution(startY, startX) << '\n';
    }
    return 0;
}