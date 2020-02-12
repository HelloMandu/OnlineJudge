#include <iostream>
#include<string>
#include<vector>
using namespace std;
#pragma warning(disable:4996)


int cache[25][25];
vector<char> temp;
int a, b;
string str, str1, str2;
bool aflag;
int combination(int n, int r) {
	if (n == r || r == 0) return 1;
	int& ret = cache[n][r];
	if (ret) return ret;
	return ret = combination(n - 1, r - 1) + combination(n - 1, r);
}

bool isSame(vector<char> & temp) {
	int count = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == str1[i]) {
			count++;
		}
	}
	if (count == temp.size()) {
		return true;
	}
	count = 0;
	for (int i = 0; i < temp.size(); i++) {
		if (temp[i] == str2[i]) {
			count++;
		}
	}
	if (count == temp.size()) {
		return true;
	}
	return false;
}

void dfs(int index, int count = 0) {
	if (count == str1.length()) {
		if (!isSame(temp)) {
			if (!aflag) {
				cout << combination(a, b) << '\n';
				cout << str1 << ' ';
				aflag = true;
			}
			for (int i = 0; i < temp.size(); i++) {
				printf("%c", temp[i]);
			}
			printf(" ");

		}
		return;
	}
	for (int i = index; i < str.length(); i++) {
		temp.push_back(str[i]);
		dfs(i + 1, count + 1);
		temp.pop_back();
	}
}

int main() {

	int asdasd = false + 1;
	cout << asdasd;
	/*cin >> a >> b;
	cin >> str >> str1 >> str2;
	dfs(0, 0);
	if (aflag) {
		cout << str2;
	}
	else {
		cout << -1;
	}*/
	return 0;
}