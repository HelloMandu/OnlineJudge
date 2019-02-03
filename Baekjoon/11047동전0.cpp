#include<iostream>
using namespace std;

int money[11];

int main() {
	int n, k;
	int result = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> money[i];
	for (int i = n - 1; i > -1; i--) {
		result += k / money[i];
		k %= money[i];
	}
	cout << result;
	return 0;
}