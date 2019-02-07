#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool VPS_Check(string &str) {
	stack<char> Stack;
	for (int i = 0; i < str.length(); i++) {
		if(str[i] == '(') // ( 일때
			Stack.push(str[i]);
		else { // ) 일때
			if (Stack.empty()) // 스택이 비어잇으면 괄호가 안맞으므로 false
				return false;
			Stack.pop(); // ( 와 ) 가 맞으므로 pop
		}
	}
	return Stack.empty() ? true : false; // 스택이 비어잇을시 true
}

int main() {
	
	int n;
	string str;
	cin >> n;
	while (n--) {
		cin >> str;
		if (VPS_Check(str))
			cout << "YES\n";
		else
			cout << "NO\n";
	}

	return 0;
}