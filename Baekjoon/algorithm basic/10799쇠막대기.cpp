#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    int result = 0;
    string str;
    stack<char> Stack;
    cin >> str;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == '('){
            Stack.push(str[i]);
        } else {
            Stack.pop();
            if(str[i - 1] == '('){
                result += Stack.size();
            } else{
                result++;
            }
        }
    }
    cout << result;
    return 0;
}