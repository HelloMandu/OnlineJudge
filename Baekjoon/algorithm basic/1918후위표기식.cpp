#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main(){
    // freopen("input.txt", "r", stdin);
    string expression, result;
    stack<char> Stack;
    cin >> expression;
    for(int i = 0; i < expression.size(); i++){
        char cur = expression[i];
        if(cur >= 'A' && cur <= 'Z'){
            result += cur;
            continue;
        }
        if(cur == '('){
            Stack.push(cur);
        } else if(cur == '*' || cur == '/'){
            while(!Stack.empty() && (Stack.top() == '*' || Stack.top() == '/')){
                result += Stack.top();
                Stack.pop();
            }
            Stack.push(cur);
        } else if(cur == '+' || cur == '-'){
            while(!Stack.empty() && Stack.top() != '('){
                result += Stack.top();
                Stack.pop();
            }
            Stack.push(cur);
        } else if(cur == ')'){
            while(!Stack.empty() && Stack.top() != '('){
                result += Stack.top();
                Stack.pop();
            }
            Stack.pop();
        }
    }
    while(!Stack.empty()){
        result += Stack.top();
        Stack.pop();
    }
    cout << result << '\n';
    return 0;
}