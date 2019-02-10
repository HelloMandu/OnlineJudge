/*유클리드 호제법을 이용해 최소공배수 구하기*/
#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

inline int getGcd(int num1, int num2) {
	return num1 ? getGcd(num2 % num1, num1) : num2;
}

int main() {
	fastIO();
	int n;
	cin >> n;
	while (n--) {
		int num1, num2, gcd;
		cin >> num1 >> num2;
		gcd = getGcd(num1, num2);
		cout << (num1 / gcd) * num2 << '\n';
	}
	return 0;
}