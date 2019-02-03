#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	stack<char> Stack;
	string str;
	int result = 0, mul = 1;
	cin >> str;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(') {
			mul *= 2;
			Stack.push('(');
			if (i + 1 < str.length() && str[i + 1] == ')')
				result += mul;
		}
		else if (str[i] == '[') {
			mul *= 3;
			Stack.push('[');
			if (i + 1 < str.length() && str[i + 1] == ']')
				result += mul;
		}

		if (!Stack.empty()) {
			if (str[i] == ')') {
				mul /= 2;
				if (Stack.top() == '(')
					Stack.pop();
			}
			else if (str[i] == ']') {
				mul /= 3;
				if (Stack.top() == '[')
					Stack.pop();
			}
		}
	}
	if (Stack.empty())
		cout << result;
	else
		cout << 0;
	return 0;
}

