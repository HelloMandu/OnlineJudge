#include<bits/stdc++.h>
using namespace std;

int cnt[2];
char str[10000001];
int main(){
    cin >> str;
    for(int i = 0; i < strlen(str); i++){
        int &ret = cnt[str[i] - '0'];
        ret++;
        while(str[i] == str[i + 1]){
            i++;
        } 
    }
    cout << min(cnt[0], cnt[1]);
    return 0;
}