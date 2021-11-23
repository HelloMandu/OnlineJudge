#include<bits/stdc++.h>
using namespace std;

const int MAX = 10;
int arr[MAX][MAX];
int result = 101;

int confetti[6] = {0, 5, 5, 5, 5, 5};

bool isFinish(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            if(arr[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

bool canPaint(int y, int x, int length){
    if(confetti[length] == 0){
        return false;
    } else if(y + length > MAX || x + length > MAX){
        return false;
    }
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){
            if(arr[i][j] != 1){
                return false;
            }
        }
    }
    return true;
}

void paint(int y, int x, int length, int type){
    if(!type){
        confetti[length]--;
    } else{
        confetti[length]++;
    }
    for(int i = y; i < y + length; i++){
        for(int j = x; j < x + length; j++){
            arr[i][j] = type;
        }
    }
}

void traverse(int y = 0, int x = 0, int cnt = 0){
    if(cnt > result){
        return;
    } else if(isFinish()){
        result = min(result, cnt);
        return;
    } else if(y == MAX){
        return;
    } else if(x == MAX){
        traverse(y + 1, 0, cnt);
        return;
    } else if(arr[y][x] != 1){
        traverse(y, x + 1, cnt);
        return;
    }
    for(int i = 5; i >= 1; i--){
        if(canPaint(y, x, i)){
            paint(y, x, i, 0);
            traverse(y, x + 1, cnt + 1);
            paint(y, x, i, 1);
        }
    }
}

int main(){
    for(int i = 0; i < MAX; i++){
        for(int j = 0; j < MAX; j++){
            cin >> arr[i][j];
        }
    }
    traverse();
    cout << (result == 101 ? -1 : result);
    return 0;
}