#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int n;
int map[101][101];
char turn[10001];
int dir = 1;
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
queue<pair<int, int> > snake;
int snakeY = 0, snakeX = 0;
int currentTime = 0;

bool isRange(int y, int x){
    return y > -1 && y < n && x > -1 && x < n;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    int apple;
    cin >> apple;
    for(int i = 0; i < apple; i++){
        int y, x;
        cin >> y >> x;
        map[y - 1][x - 1] = 2;
    }
    int l;
    cin >> l;
    for(int i = 0; i < l; i++){
        int next; char lr;
        cin >> next >> lr;
        turn[next] = lr;
    }
    snake.push(make_pair(0, 0));
    map[0][0] = 1;
    while(true){
        snakeY += dy[dir];
        snakeX += dx[dir];
        currentTime++;
        if(!isRange(snakeY, snakeX) || map[snakeY][snakeX] == 1){
            break;
        }
        if(map[snakeY][snakeX] != 2){
            int tailY = snake.front().first;
            int tailX = snake.front().second;
            map[tailY][tailX] = 0;
            snake.pop();
        }
        snake.push(make_pair(snakeY, snakeX));
        map[snakeY][snakeX] = 1;
        if(turn[currentTime] == 'D'){
            dir = (dir + 5) % 4;
        } else if(turn[currentTime] == 'L'){
            dir = (dir + 3) % 4;
        }
    }

    cout << currentTime << '\n';
    return 0;
}
