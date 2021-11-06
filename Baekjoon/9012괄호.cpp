#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool isVps(string &str) {
	stack<char> Stack;
	for (int i = 0; i < str.length(); i++) {
		if(str[i] == '('){
			Stack.push(str[i]);
		}
		else if(Stack.empty()){
			return false;
		} else{
			Stack.pop();
		}
	}
	return Stack.empty();
}

int main() {
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		cout << (isVps(str) ? "YES\n" : "NO\n");
	}
	return 0;
}