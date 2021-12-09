#include<bits/stdc++.h>
using namespace std;

struct Shark{
    bool exist;
    int s, d, z;
    Shark() {}
    Shark(int _s, int _d, int _z, bool _exist): s(_s), d(_d), z(_z), exist(_exist) {};
};

int r, c, m;
Shark arr[101][101];
int dy[5] = {0, -1, 1, 0, 0}; // 상, 하, 우, 좌
int dx[5] = {0, 0, 0, 1, -1};

void moveShark(){
    Shark newArr[101][101];
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            Shark shark = Shark(0, 0, 0, false);
            newArr[i][j] = shark;
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            Shark cur = arr[i][j];
            if(!cur.exist){
                continue;
            }
            bool isY = cur.d == 1 || cur.d == 2; 
            if(!isY){
                int x = j;
                int dir = cur.d;
                for(int k = 0; k < cur.s; k++){
                    if(x == c && dir == 3){
                        dir = 4;
                    } else if(x == 1 && dir == 4){
                        dir = 3;
                    }
                    x += dx[dir];
                }
                if(newArr[i][x].z < cur.z){
                    newArr[i][x] = Shark(cur.s, dir, cur.z, true);
                }
            } else{
                int y = i;
                int dir = cur.d;
                for(int k = 0; k < cur.s; k++){
                    if(y == r && dir == 2){
                        dir = 1;
                    } else if(y == 1 && dir == 1){
                        dir = 2;
                    }
                    y += dy[dir];
                }
                if(newArr[y][j].z < cur.z){
                    newArr[y][j] = Shark(cur.s, dir, cur.z, true);
                }
            }
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            arr[i][j] = newArr[i][j];
        }
    }
}

int solution(){
    int result = 0;
    for(int x = 1; x <= c; x++){
        for(int y = 1; y <= r; y++){
            if(arr[y][x].exist){
                arr[y][x].exist = false;
                result += arr[y][x].z;
                break;
            }
        }
        moveShark();
    }
    return result;
}

int main(){
    cin >> r >> c >> m;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            Shark shark = Shark(0, 0, 0, false);
             arr[i][j] = shark;
        }
    }
    for(int i = 0; i < m; i++){
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        arr[r][c] = Shark(s, d, z, true);
    }
    cout << solution();
    return 0;
}