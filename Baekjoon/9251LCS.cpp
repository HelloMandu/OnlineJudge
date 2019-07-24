#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
string str1, str2;
int cache[1001][1001];
void lcs() {
	int result = 0;
	for (int i = 1; i <= str2.length(); i++) {
		for (int j = 1; j <= str1.length(); j++) {
			if (str2[i - 1] == str1[j - 1]) {
				cache[i][j] = cache[i - 1][j - 1] + 1;
			}
			else {
				cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
			}
		}
	}
}

int main() {
	cin >> str1 >> str2;
	lcs();
	cout << cache[str2.length()][str1.length()];
	return 0;
}