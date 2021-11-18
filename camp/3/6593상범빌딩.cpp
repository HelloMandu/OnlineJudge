#include<bits/stdc++.h>
using namespace std;

int l,r, c;
char arr[31][31][31];
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dx[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
struct Loc {
    int y, x, z, length;
    Loc(int _z, int _y, int _x, int _length) :z(_z),y(_y),x(_x),length(_length) {}
};

bool isRange(int z, int y, int x){
    return z < l && z >= 0 && y < r && y >= 0 && x < c && x >= 0;
}

int traverse(int z, int y, int x){
    queue<Loc> Queue;
    Queue.push(Loc(z, y, x, 0));
    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        for(int i = 0; i < 6; i++){
            int nextY = cur.y + dy[i];
		    int nextX = cur.x + dx[i];
		    int nextZ = cur.z + dz[i];
            if (isRange(nextZ, nextY, nextX) && arr[nextZ][nextY][nextX] != '#') {
                if(arr[nextZ][nextY][nextX] == 'E'){
                    return cur.length + 1;
                }
                arr[nextZ][nextY][nextX] = '#';
                Queue.push(Loc(nextZ, nextY, nextX, cur.length + 1));
            }
        }
    }
    return 0;
}

void solution(){
    for(int i = 0; i < l; i++){
        for(int j = 0; j < r; j++){
            for(int k = 0; k < c; k++){
                if(arr[i][j][k] == 'S'){
                    int result = traverse(i, j, k);
                    if(result > 0){
                        cout << "Escaped in "<< result << " minute(s).\n";
                    } else{
                        cout << "Trapped!\n";
                    }
                    return;
                }
            }
        }
    }
}

int main(){
    while(cin >> l >> r >> c){
        if(l == 0 && r == 0 && c == 0){
            return 0;
        }
        for(int i = 0; i < l; i++){
            for(int j = 0; j < r; j++){
                for(int k = 0; k < c; k++){
                    cin >> arr[i][j][k];
                }
            }
        }
        solution();
    }
    return 0;
}