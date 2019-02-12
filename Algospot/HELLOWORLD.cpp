#include<iostream>
#include<string>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string str;
		cin >> str;
		cout << "Hello, " << str << "!\n";
	}
	return 0;
}