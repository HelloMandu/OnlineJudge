#include<iostream>
#include<string>
#include<cstring>
#define MAX 7
using namespace std;

char boggle[MAX][MAX] = { 0 };
bool cache[10][MAX][MAX];
string word;

void initBoggle() { 
	for (int i = 1; i < MAX - 1; i++){
		for (int j = 1; j < MAX - 1; j++){
			cin >> boggle[i][j];
		}
	}
}

bool findWord(int i, int j, int present) {
	if (present == word.size()) {
		return true;
	}
	for (int y = i - 1; y <= i + 1; y++) {
		for (int x = j - 1; x <= j + 1; x++) {
			if (y != i || x != j) { 
				if (boggle[y][x] == word[present] && !cache[present][y][x]) { 
					cache[present][y][x] = true; 
					if (findWord(y, x, present + 1)){
						return true;
					}
				}
			}
		}
	}
	return false;
}

bool checkWord() {
	int present = 0;
	for (int i = 1; i < MAX - 1; i++) {
		for (int j = 1; j < MAX - 1; j++) {
			if (boggle[i][j] == word[present]) {
				if (findWord(i, j, present + 1)){
					return true;
				}
			}
		}
	}
	return false;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int wordNum;
		initBoggle();
		cin >> wordNum;
		while (wordNum--) {
			cin >> word;
			cout << word << (checkWord() ? " YES" : " NO") << '\n';
			memset(cache, false, sizeof(cache));
		}
	}
	return 0;
}