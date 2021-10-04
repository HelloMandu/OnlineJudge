#include<bits/stdc++.h>
using namespace std;

int depth, days;
double cache[1001][2002];

double climb(int _days, int height){
    double& ret = cache[_days][height];
    if(_days == days){
        return ret = height >= depth ? 1 : 0;
    }
    if(ret != -1){
        return ret;
    }
    return ret = 0.75 * climb(_days + 1, height + 2) + 0.25 * climb(_days + 1, height + 1);
}

int main(){
    // freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        for (int i = 0; i < 1001; i++){
            for (int j = 0; j < 2002; j++){
                cache[i][j] = -1.0;
            }
        }
        cin >> depth >> days;
        cout.precision(11);
        cout << climb(0, 0) << '\n';
    }
    return 0;
}