#include<stdio.h>
#pragma warning(disable :4996)

int main() {
	int n, cnt = 0;
	int ten, one, newone; // n/10, n%10, (ten + one) % 10;

	scanf("%d", &n);

	int temp = n;

	while (1) {
		ten = n / 10;
		one = n % 10;
		newone = (ten + one) % 10;
		n = one*10 + newone;
		cnt++;
		if (temp == n) break;
	}
	printf("%d\n", cnt);
	return 0;
}