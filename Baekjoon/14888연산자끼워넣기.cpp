#include<iostream>
#include<algorithm>
using namespace std;

int n;
int num[12];
int oper[4];
int maxResult = -100000000, minResult = 1000000000;

void operation(int result, int depth) {
	if (depth == n) {
		maxResult = max(maxResult, result);
		minResult = min(minResult, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			switch (i) {
			case 0:
				operation(result + num[depth], depth + 1);
				break;
			case 1:
				operation(result - num[depth], depth + 1);
				break;
			case 2:
				operation(result * num[depth], depth + 1);
				break;
			case 3:
				operation(result / num[depth], depth + 1);
				break;
			}
			oper[i]++;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	operation(num[0], 1);
	cout << maxResult << '\n' << minResult;
	return 0;
}