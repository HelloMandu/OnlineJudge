#include<iostream>
#include<vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;
typedef long long lint;

lint num[100];
vector<lint> result;

inline lint getGcd(lint num1, lint num2) {
	return num1 ? getGcd(num2 % num1, num1) : num2;
}

void setResult(int n) {
	int gcd;
	while (true) {
		for (int i = 0; i < n - 1; i++) {
			gcd = getGcd(num[i], num[i + 1]);
		}
		result.push_back(gcd);
		for (int i = 0; i < n; i++) {
			num[i] -= gcd;
			if (!num[i]) {
				return;
			}
		}
	}
}

int main() {
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	setResult(n);
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}