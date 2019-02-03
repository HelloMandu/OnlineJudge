#include<iostream>
using namespace std;

int money[6] = { 500, 100, 50, 10, 5, 1 };

int main() {
	int input;
	cin >> input;
	int n = 1000 - input, result = 0;
	for (int i = 0; i < 6; i++) {
		result += n / money[i];
		n %= money[i];
	}
	cout << result;
	return 0;
}