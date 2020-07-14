#include<iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int e, f, c;
	cin >> e >> f >> c;
	int remained = e + f;
	int result = 0;
	while (remained >= c) {
		result += remained / c;
		remained = remained / c + remained % c;
	}
	cout << result;
	return 0;
}