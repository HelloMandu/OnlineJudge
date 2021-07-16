#include<iostream>
#include<string>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    string str, result;
    getline(cin, str);
    for(int i = 0; i < str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            char newChar = (char)(((str[i] - 'a' + 13) % 26) + 'a');
            result += newChar;
        } else if(str[i] >= 'A' && str[i] <= 'Z'){
            char newChar = (char)(((str[i] - 'A' + 13) % 26) + 'A');
            result += newChar;
        } else{
            result += str[i];
        }
    }
    cout << result << '\n';
    return 0;
}