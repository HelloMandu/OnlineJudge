#include<iostream>
#define MOD 1000000
using namespace std;
const int pisano = MOD / 10 * 15;
int fibo[pisano] = { 0, 1 };
int main() {
	long long n;
	cin >> n;
	for (int i = 2; i <= n % pisano; i++)
		fibo[i] = (fibo[i - 1] + fibo[i - 2]) % MOD;
	cout << fibo[n%pisano];
	return 0;
}