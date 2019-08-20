#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string str;
string word[101];
int cache[101];
int n;

bool canMake(int index = 0) {
	if (cache[index] != -1) {
		return cache[index];
	}
	else if (index == str.length()) {
		return cache[index] = 1;
	}
	cache[index] = 0;
	for (int i = 0; i < n; i++) {
		if (index + word[i].length() <= str.length()) {
			bool isSame = true;
			for (int j = 0; j < word[i].length(); j++) {
				if (str[index + j] != word[i][j]) {
					isSame = false;
				}
			}
			if (isSame) {
				cache[index] += canMake(index + word[i].length());
			}
		}
	}
	return cache[index];
}

int main() {
	cin >> str >> n;
	for (int i = 0; i < n; i++) {
		cin >> word[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << canMake();
	return 0;
}
