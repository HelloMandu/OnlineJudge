#include<iostream>
#include<string>
#define MAX 151
using namespace std;

int main() {
	string player[MAX];
	int alphabet[26] = { 0 };
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> player[i];
		alphabet[player[i][0] - 'a']++;
	}
	int count = 0;
	bool flag = false;
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] > 4) {
			cout << (char)(i + 'a');
			flag = true;
		}
	}
	if (!flag)
		cout << "PREDAJA";
	return 0;
}