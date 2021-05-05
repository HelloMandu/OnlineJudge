#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    while(true){
        string str;
        stack<char> Stack;
        getline(cin, str);
        if(str == "."){
            break;
        }
        bool flag = false;
        for(int i = 0; i < str.length(); i++){
            char cur = str[i];
            if(cur == '[' || cur == '('){
                Stack.push(cur);
            } else if(cur == ']'){
                if(Stack.empty() || Stack.top() != '['){
                    flag = true;
                    break;
                }
                Stack.pop();
            } else if(cur == ')'){
                if(Stack.empty() || Stack.top() != '('){
                    flag = true;
                    break;
                }
                Stack.pop();
            }
        }
        if(!flag && Stack.empty()){
            cout << "yes\n";
        } else{
            cout << "no\n";
        }
    }

    return 0;
}