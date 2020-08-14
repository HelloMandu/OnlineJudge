#include<iostream>
#include<cstring>
using namespace std;

int main() {
	char str[1001];
	int n;
	cin >> n;
	while (n--) {
	cin >> str;
	cout << str[0] << str[strlen(str) - 1] << '\n';
	}
	return 0;
}