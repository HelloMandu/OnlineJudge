#include<iostream>
#include<string>
#include<vector>
using namespace std;

char str[1001];

vector<string> split(string str, char c){
    vector<string> strList;
    string sliced = "";
    for(int i = 0; i < str.length(); i++){
        if(str[i] == c){
            strList.push_back(sliced);
            sliced = "";
        } else{
            sliced += str[i];
        }
    }
    strList.push_back(sliced);
    return strList;
}

int main(){
    // freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    cin.ignore();
    while(n--){
        string str;
        while(getline(cin, str)){
            vector<string> strList = split(str, ' ');
            for(int i = 0; i < strList.size(); i++){
                for(int j = strList[i].length() - 1; j >= 0; j--){
                    cout << strList[i][j];
                }
                cout << ' ';
            }
            cout << '\n';
        }
    }
    return 0;
}