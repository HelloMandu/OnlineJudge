#include<iostream>
#include<cmath>
using namespace std;

void GetResult(int n) {
	for (int i = 2; i <= sqrt(n); i++) {
		while (n % i == 0) {
			cout << i << '\n';
			n /= i;
		}
	}
	if (n > 1)
		cout << n << '\n';
}

int main() {
	int n;
	cin >> n;
	GetResult(n);
	return 0;
}