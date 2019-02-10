/*��Ŭ���� ȣ������ �̿��� �ּҰ���� ���ϱ�*/
#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

inline long long getGcd(long long num1, long long num2) {
	return num1 ? getGcd(num2 % num1, num1) : num2;
}

int main() {
	fastIO();
	long long num1, num2, gcd;
	cin >> num1 >> num2;
	gcd = getGcd(num1, num2);
	cout << (num1 / gcd) * num2;
	return 0;
}