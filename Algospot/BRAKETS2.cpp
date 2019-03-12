#include<iostream>
#include<string>
#include<stack>
using namespace std;

string brakets;

bool isWellMatched() {
	const string opening = "({[", closing = ")}]";
	stack<char> Stack;
	for (int i = 0; i < brakets.size(); i++) {
		/*여는 괄호 일 때*/
		if (opening.find(brakets[i]) != -1) {
			Stack.push(brakets[i]);
		}
		/*닫는 괄호 일 때*/
		else {
			/*스택이 비어 있을 때*/
			if (Stack.empty()) {
				return false;
			}
			/*쌍이 맞지 않을 떄*/
			else if (opening.find(Stack.top()) != closing.find(brakets[i])) {
				return false;
			}
			Stack.pop();
		}
	}
	return Stack.empty() ? true : false;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> brakets;
		cout << (isWellMatched() ? "YES" : "NO") << '\n';
	}
	return 0;
}