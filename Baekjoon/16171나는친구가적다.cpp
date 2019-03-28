#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

string str1, str2, realstr;

int included() {
	int str1size = 0;
	for (int i = 0; i < str1.size(); i++) {
		if (str1[i] >= '0' && str1[i] <= '9') {
			continue;
		}
		else {
			realstr += str1[i];
		}
	}
	bool flag = false;
	for (int i = 0; i < realstr.size(); i++) {
		for (int j = 0; j < str2.size() && i + str2.size() <= realstr.size(); j++) {
			if (realstr[i + j] != str2[j]) {
				flag = false;
				break;
			}
			flag = true;
		}
		if (flag) {
			return 1;
		}
	}
	return 0;
}

int main() {
	fastIO();
	cin >> str1 >> str2;
	cout << included() << '\n';
	return 0;
}