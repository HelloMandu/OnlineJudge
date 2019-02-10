#include<iostream>
#include<vector>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int num[100];
vector<int> result;

inline int getGcd(int num1, int num2) {
	return num1 ? getGcd(num2 % num1, num1) : num2;
}

void setResult(int n) {
	int gcd = num[1] - num[0];
	for (int i = 1; i < n - 1; i++) { // 소수구하기
		gcd = (gcd < (num[i + 1] - num[i])) ? getGcd(gcd, num[i + 1] - num[i]) : getGcd(num[i + 1] - num[i], gcd);
	}

	for (int i = 2; i * i <= gcd; i++) { // 최대공약수의 약수를 구한다
		if (gcd%i == 0) {
			result.push_back(i);
			if (i * i < gcd) {
				result.push_back(gcd / i);
			}
		}
	}
	result.push_back(gcd);
}

int main() {
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	sort(num, num + n);
	setResult(n);
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << ' ';
	}
	return 0;
}