#include<iostream>
using namespace std;
/*int Fibo(int n) { // 시간복잡도 logn
	if (n <= 1)
		return n;
	return Fibo(n - 2) + Fibo(n - 1);
}*/
long Fibo2(int n) { // 시간복잡도 n
	if (n <= 1)
		return n;
	long fibo[100];
	fibo[0] = 0; fibo[1] = 1;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	return fibo[n];
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	cout << Fibo2(n);
	return 0;
}