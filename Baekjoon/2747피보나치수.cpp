#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996)

/*int Fibo(int n) { // 시간복잡도 logn
	if (n <= 1)
		return n;
	return Fibo(n - 2) + Fibo(n - 1);
}*/
int Fibo2(int n) { // 시간복잡도 n
	if (n <= 1)
		return n;
	int first = 0, second = 1, sum = 0;
	for (int i = 2; i <= n; i++) {
		sum = first + second;
		first = second;
		second = sum;
	}
	return sum;
}
int main() {
	int n;

	scanf("%d", &n);
	
	printf("%d\n", Fibo2(n));

	return 0;
}