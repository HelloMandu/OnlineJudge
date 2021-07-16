#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool isOperator(char c){
    return c == '*' || c == '/' || c == '+' || c == '-';
}

double myOperator(char oper, double n, double m){
    if(oper == '*'){
        return n * m;
    } else if(oper == '/'){
        return n / m;
    } else if(oper == '+'){
        return n + m;
    }
    return n - m;
}

int arr[27];

int main(){
    freopen("input.txt", "r", stdin);
    int n;
    string str;
    stack<double> Stack;
    cin >> n >> str;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int cur = 0;
    for(int i = 0; i < str.size(); i++){
        if(isOperator(str[i])){
            double second = Stack.top(); Stack.pop();
            double first = Stack.top(); Stack.pop();
            Stack.push(myOperator(str[i], first, second));
        } else{
            Stack.push(arr[str[i] - 'A']);
        }
    }
    printf("%.2lf", Stack.top());
    return 0;
}