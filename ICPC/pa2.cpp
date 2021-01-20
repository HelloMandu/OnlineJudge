#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;
	int result = 2;
	for (int i = 3; i <= n; i += 2) {
		result = result * 2 % 16769023;
	}
	cout << result;
	return 0;
}