#include<bits/stdc++.h>
using namespace std;

int w, h;
char arr[1001][1001];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

struct Loc{
    int y, x, length;
    Loc(int _y, int _x, int _length): y(_y), x(_x), length(_length) {}
};

bool isRange(int y, int x) {
	return y >= h || y < 0 || x >= w || x < 0;
}

int traverse(int y, int x){
    queue<Loc> Queue;
    Queue.push(Loc(y, x, 0));
    while(!Queue.empty()){
        Loc cur = Queue.front(); Queue.pop();
        for(int i = 0; i < 4; i++){
            int nextY = y + dy[i];
            int nextX = x + dx[i];
                cout << nextY << ' ' << nextX <<  ' ' << isRange(nextY, nextX) << '\n';
            if(isRange(nextY, nextX)){
                return cur.length + 1;
            } else if (arr[nextY][nextX] == '*') {
                arr[nextY][nextX] = '.';
                Queue.push(Loc(nextY, nextX, cur.length + 1));
            }
		}
	}
    return 0;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> w >> h;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                cin >> arr[i][j];
            }
        }
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                if(arr[i][j] == '@'){
                    int result = traverse(i, j);
                    if(result > 0){
                        cout << result << '\n';
                    } else{
                        cout << "IMPOSSIBLE" << '\n';
                    }
                }
            }
        }
    }
    return 0;
}