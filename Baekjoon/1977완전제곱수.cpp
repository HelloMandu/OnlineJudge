#include<iostream>
#include<cmath>
#define Min(a, b) a > b ? b : a
using namespace std;

void GetResult(int n, int m) {
	int sum = 0;
	int min = 100000000;
	for (int i = sqrt(n); i <= sqrt(m); i++) {
		if (i*i >= n && i*i <= m) {
			sum += i * i;
			min = Min(min, i * i);
		}
	}
	if (sum)
		cout << sum << '\n' << min;
	else
		cout << "-1";
}

int main() {
	int n, m;
	cin >> n >> m;
	GetResult(n, m);
	return 0;
}