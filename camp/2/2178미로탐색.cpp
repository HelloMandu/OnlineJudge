#include<bits/stdc++.h>
using namespace std;

int n, m;
char arr[101][101];
int dY[4] = { -1, 0, 1, 0 };
int dX[4] = { 0, 1, 0, -1 };
int isVisit[101][101];

struct Coord{
    int y, x;
};

bool isRange(int y, int x){
    return y >= 0 && y < n && x >= 0 && x < m;
}

int solution(){
    queue<Coord> Queue;
    Coord first;
    first.y = 0;
    first.x = 0;
    Queue.push(first);
    isVisit[0][0] = 1;
    while(!Queue.empty()){
        Coord first = Queue.front(); Queue.pop();
        if(first.y == n - 1 && first.x == m - 1){
            return isVisit[first.y][first.x];
        }
        for(int i = 0; i < 4; i++){
            int dy = first.y + dY[i];
            int dx = first.x + dX[i];
            if(isRange(dy, dx) && arr[dy][dx] == '1' && !isVisit[dy][dx]){
                Coord newCoord;
                newCoord.y = dy;
                newCoord.x = dx;
                isVisit[dy][dx] = isVisit[first.y][first.x] + 1;
                Queue.push(newCoord);
            }
        }
    }
    return -1;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    cout << solution();
    return 0;
}