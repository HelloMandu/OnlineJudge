#include<bits/stdc++.h>
using namespace std;

int cache[10001];
string str;

bool isSameStr(int start, int end){
    for(int i = start; i < end; i++){
        if(str[i] != str[i + 1]){
            return false;
        }
    }
    return true;
}

bool isMinorDiff(int start, int end){
    int diff = str[start + 1] - str[start];
    if(abs(diff) != 1){
        return false;
    }
    for(int i = start; i < end; i++){
        if((str[i + 1] - str[i]) != diff){
            return false;
        }
    }
    return true;
}

bool isRepeat(int start, int end){
    string sliced = str.substr(start, end - start + 1);
    for(int i = 0; i < sliced.length(); i++){
        if(sliced[i] != sliced[i % 2]){
            return false;
        }
    }
    return true;
}

bool isSequence(int start, int end){
    int diff = str[start + 1] - str[start];
    for(int i = start; i < end; i++){
        if((str[i + 1] - str[i]) != diff){
            return false;
        }
    }
    return true;
}

int classify(int start, int end){
    if(isSameStr(start, end)){
        return 1;
    } else if(isMinorDiff(start, end)){
        return 2;
    } else if(isRepeat(start, end)){
        return 4;
    } else if(isSequence(start, end)){
        return 5;
    }
    return 10;
}

int solution(int start){
    if(start == str.length()){
        return 0;
    }
    int& ret = cache[start];
    if(ret != -1){
        return ret;
    }
    ret = 987654321;
    for(int i = 3; i <= 5; i++){
        if(start + i <= str.length()){
            ret = min(ret, classify(start, start + i - 1) + solution(start + i));
        }
    }
    return ret;
}

int main(){
    freopen("../input.txt", "r", stdin);
    int t;
    cin >> t;
    while(t--){
        memset(cache, -1, sizeof(cache));
        cin >> str;
        cout << solution(0) << '\n';
    }
    return 0;
}