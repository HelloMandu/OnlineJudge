#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
using namespace std;
int n, m;
bool isError[10];

int getLength(int num) {
	if (num / 10 == 0) {
		return 1;
	}
	return log10(num) + 1;
}

bool canClick(int num) {
	string str = to_string(num);
	for (int i = 0; i < str.length(); i++) {
		if (isError[str[i] - '0']) {
			return false;
		}
	}
	return true;
}


int minButton() {
	int result = abs(n - 100);
	for (int i = 0; i < 1000000; i++) {
		if (canClick(i)) {
			int length = getLength(i);
			result = min(result, abs(n - i) + length);
		}
	}
	return result;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int button;
		cin >> button;
		isError[button] = true;
	}
	cout << minButton();
	return 0;
}