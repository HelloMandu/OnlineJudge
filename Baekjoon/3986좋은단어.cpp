#include<iostream>
#include<cstring>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	int result = 0;
	while (testcase--) {
		char word[100001];
		char stack[100001];
		int top = -1;
		cin >> word;
		int len = strlen(word);
		for (int i = 0; i < len; i++) {
			if (top != -1) {
				if (stack[top] == word[i]) {
					top--;
				}
				else {
					stack[++top] = word[i];
				}
			}
			else {
				stack[++top] = word[i];
			}
		}
		if (top == -1) {
			result++;
		}
	}
	cout << result;
	return 0;
}