#include <iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	string str, result;
	cin >> str;
	result += str[0];
	for (int i = 0; i < str.size() - 1; i++) {
		if (str[i] == '-')
			result += str[i + 1];
	}
	cout << result;
	return 0;
}