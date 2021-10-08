#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int bino[201][201];

void solution(int n, int m, string result = ""){
    if(k < 0){
        return;
    }
    if(n == 0 && m == 0){
        k--;
        if(k == 0){
            cout << result << '\n';
        }
        return;
    }
    if(bino[n + m][m] < k){
        k -= bino[n + m][m];
        return;
    }
    if(n > 0) {
        solution(n - 1, m, result + '-');
    }
    if(m > 0) {
        solution(n, m - 1, result + 'o');
    }
 }

int main(){
    freopen("../input.txt", "r", stdin);
    for(int i = 1; i < 201; i++){
        bino[i][0] = bino[i][i] = 1;
        for(int j = 1; j < i; j++){
            bino[i][j] = min(1000000000, bino[i - 1][j] + bino[i - 1][j - 1]);
        }
    }
    int testcase;
    cin >> testcase;
    while(testcase--){
        cin >> n >> m >> k;
        solution(n, m, "");
    }
    return 0;
}