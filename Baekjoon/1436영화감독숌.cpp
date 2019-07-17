#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
	int n;
	cin >> n;
	int num = 0;
	while (n) {
		num++;
		string str = to_string(num);
		if (str.find("666") != string::npos) {
			n--;
		}
	}
	cout << num;
	return 0;
}