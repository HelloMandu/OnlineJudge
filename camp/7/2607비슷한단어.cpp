#include<bits/stdc++.h>
using namespace std;

int n;
string str[101];

bool isSimilar(string str1, string str2){
    int alpha[26], alpha2[26];
    memset(alpha, 0, sizeof(alpha));
    memset(alpha2, 0, sizeof(alpha2));
    int diffL = str1.length() - str2.length();
    if(abs(diffL) > 1){
        return false;
    }
    for(int i = 0; i < str1.length(); i++){
        alpha[str1[i] - 'A']++;
    }
    for(int i = 0; i < str2.length(); i++){
        alpha2[str2[i] - 'A']++;
    }
    int diff = 0;
    bool flag = false;
    bool flag2 = false;
    for(int i = 0; i < 26; i++){
        int d = abs(alpha[i] - alpha2[i]);
        if(d == 1){
            if(!flag){
                flag = true;
            } else if(flag2){
                return false;
            } else{
                diff -= 2;
                flag2 = true;
            }
        }
        diff += d;
    }
    return diff <= 1;
}

int solution(){
    int result = 0;
    for(int i = 1; i < n; i++){
        result += isSimilar(str[0], str[i]);
        // cout << isSimilar(str[0], str[i]) << '\n'; 
    }
    return result;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> str[i];
    }
    cout << solution();
    return 0;
}