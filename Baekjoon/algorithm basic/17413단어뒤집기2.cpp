#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    string str;
    getline(cin, str);
    string temp = "";
    bool isOpen = false;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '<'){
            reverse(temp.begin(), temp.end());
            cout << temp << str[i];
            temp = "";
            isOpen = true;
        } else if(str[i] == '>'){
            cout << temp << str[i];
            temp = "";
            isOpen = false;
        } else if(str[i] == ' '){
            if(!isOpen){
                reverse(temp.begin(), temp.end());
            }
            cout << temp << str[i];
            temp = "";
        } else{
            temp += str[i];
        }
    }
    reverse(temp.begin(), temp.end());
    cout << temp;
    return 0;
}