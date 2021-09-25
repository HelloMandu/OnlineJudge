/** 
 * TODO: retry
*/
#include<bits/stdc++.h>
using namespace std;

const int INFINITE = 987654321;
const int linked[10][16] = {
    { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1 },
    { 1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0 },
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
    { 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 },
    { 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1 },
    { 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 }
};


bool isFinish(int clocks[]){
    for(int i = 0; i < 16; i++){
        if(clocks[i] != 12){
            return false;
        }
    }
    return true;
}

void click(int clocks[], int cur){
    for(int i = 0; i < 16; i++){
        if(linked[cur][i]){
            clocks[i] += 3;
            if(clocks[i] == 15){
                clocks[i] = 3;
            }
        }
    }
}

int getMinClicked(int clocks[], int cur = 0){
    if(isFinish(clocks)){
        return 0;
    } else if(cur == 10){
        return isFinish(clocks) ? 0 : INFINITE;
    }
    int ret = INFINITE;
    for(int i = 0; i < 4; i++){
        ret = min(ret, getMinClicked(clocks, cur + 1) + i);
        click(clocks, cur);
    }
    return ret;
}

int main(){
	// freopen("input.txt", "r", stdin);
    int clocks[16];
    int t;
    cin >> t;
    while(t--){
        for(int i = 0; i < 16; i++){
            cin >> clocks[i];
        }
        int result = getMinClicked(clocks);
        cout << (result == INFINITE ? -1 : result) << '\n';
    }
    return 0;
}