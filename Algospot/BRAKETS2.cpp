#include<iostream>
#include<string>
#include<stack>
using namespace std;

string brakets;

bool isWellMatched() {
	const string opening = "({[", closing = ")}]";
	stack<char> Stack;
	for (int i = 0; i < brakets.size(); i++) {
		/*���� ��ȣ �� ��*/
		if (opening.find(brakets[i]) != -1) {
			Stack.push(brakets[i]);
		}
		/*�ݴ� ��ȣ �� ��*/
		else {
			/*������ ��� ���� ��*/
			if (Stack.empty()) {
				return false;
			}
			/*���� ���� ���� ��*/
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