#include<iostream>
#include<string>
using namespace std;

string str, bomb;
char arr[1000001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> str >> bomb;
	int index = 0;
	for (int i = 0; i < str.size(); i++) {
		arr[index++] = str[i];
		if (arr[index - 1] == bomb[bomb.size() - 1]) {
			if (index >= bomb.size()) {
				bool flag = false;
				for (int j = index - bomb.size(), b = 0; j < index; j++, b++) {
					if (arr[j] != bomb[b]) {
						flag = true;
						break;
					}
				}
				if (!flag) {
					index -= bomb.size();
				}
			}
		}
	}
	if (index) {
		for (int i = 0; i < index; i++) {
			cout << arr[i];
		}
	}
	else {
		cout << "FRULA";
	}
	return 0;
}