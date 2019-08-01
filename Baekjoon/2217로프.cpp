#include<iostream>
#include<algorithm>
using namespace std;

int n;
int rope[100001];

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> rope[i];
	}
	sort(rope, rope + n);
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, rope[i] * (n - i));
	}
	cout << result;
	return 0;
}