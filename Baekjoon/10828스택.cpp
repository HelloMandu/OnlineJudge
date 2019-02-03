#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	stack<int> Stack;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			Stack.push(num);
		}
		else if (str == "pop") {
			if (Stack.empty())
				cout << "-1" << endl;
			else {
				cout << Stack.top() << endl;
				Stack.pop();
			}
		}
		else if (str == "size")
			cout << Stack.size() << endl;
		else if (str == "empty") {
			if (Stack.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "top") {
			if (Stack.empty())
				cout << "-1" << endl;
			else
				cout << Stack.top() << endl;
		}
	}
	return 0;
}