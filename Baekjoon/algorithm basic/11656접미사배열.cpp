#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string strList[1001];

bool compare(string a, string b){
    int len = a.length() > b.length() ? b.length() : a.length();
    for(int i = 0; i < len; i++){
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return a.length() < b.length();
}

int main(){
    // freopen("input.txt", "r", stdin);
    string inputStr;
    cin >> inputStr;
    for(int i = 0; i < inputStr.size(); i++){
        strList[i] = inputStr.substr(i, (inputStr.size() - i));
    }
    sort(strList, strList + inputStr.length(), compare);
        for(int i = 0; i < inputStr.size(); i++){
        cout << strList[i] << '\n';
    }
    return 0;
}