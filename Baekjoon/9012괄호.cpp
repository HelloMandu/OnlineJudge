#include<iostream>
#include<stack>
#include<string>
using namespace std;

bool VPS_Check(string &str) {
	stack<char> Stack;
	for (int i = 0; i < str.length(); i++) {
		if(str[i] == '(') // ( �϶�
			Stack.push(str[i]);
		else { // ) �϶�
			if (Stack.empty()) // ������ ��������� ��ȣ�� �ȸ����Ƿ� false
				return false;
			Stack.pop(); // ( �� ) �� �����Ƿ� pop
		}
	}
	return Stack.empty() ? true : false; // ������ ��������� true
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