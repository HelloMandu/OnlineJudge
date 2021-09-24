#include<bits/stdc++.h>
using namespace std;

int n, m;
char board[31][31];
int dir[4][3][2] = {
    {{0, 0}, {0, 1}, {1, 0}},
    {{0, 0}, {0, 1}, {1, 1}},
    {{0, 0}, {1, 0}, {1, -1}},
    {{0, 0}, {1, 0}, {1, 1}},
};

bool isRange(int y, int x){
    return y > -1 && y < n && x > -1 && x < m;
}

bool canCover(char board[][31], int _y, int _x, int count){
    for(int i = 0; i < 3; i++){
        const int y = _y + dir[count][i][0];
        const int x = _x + dir[count][i][1];
        if(!isRange(y, x) || board[y][x] == '#'){
            return false;
        }
    }
    return true;
}

void paintBoard(char board[][31],int _y, int _x, int count, char c){
    for(int i = 0; i < 3; i++){
        const int y = _y + dir[count][i][0];
        const int x = _x + dir[count][i][1];
        board[y][x] = c;
    }
}

int getCountCover(char board[][31]){
    int y = -1, x = -1;
    for(int i = 0; i < n; i++){ 
        for(int j = 0; j < m; j++){
            if(board[i][j] == '.'){
                y = i;
                x = j;
                break;
            }
        }
        if (y != -1) {
			break;
		}
    }
    if(y == -1){
        return 1;
    }

    int ret = 0;
    for(int k = 0; k < 4; k++){
        if(canCover(board, y, x, k)){
            paintBoard(board, y, x, k, '#');
            ret += getCountCover(board);
            paintBoard(board, y, x, k, '.');
        }
    }
    return ret;
}

int main(){
	// freopen("input.txt", "r", stdin);
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> board[i][j];
            }
        }
        cout << getCountCover(board) << '\n';
    }

    return 0;
}