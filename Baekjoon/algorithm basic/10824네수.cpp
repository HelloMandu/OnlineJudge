#include<iostream>
#include<string>
using namespace std;

long long stringToNumber(string str){
    long long n = 0;
    for(int i = 0; i < str.size(); i++){
        n *= 10;
        n += (str[i] - '0');
    }
    return n;
}

int main(){
    freopen("input.txt", "r", stdin);
    string str[4];
    for(int i = 0; i < 4; i++){
        cin >> str[i];
    }
    string first = str[0] + str[1];
    string second = str[2] + str[3];
    cout << stringToNumber(first) + stringToNumber(second);
    return 0;
}