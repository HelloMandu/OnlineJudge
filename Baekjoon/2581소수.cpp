#include<stdio.h>
#pragma warning(disable:4996)
int sum = 0, min = 0;
void sosu(int m, int n) {
	int i, j;
	for (i = m; i <= n; i++) {
		for (j = 2; j < i; j++) {
			if (i%j == 0)
				break;
		}
		if (i == j) {
			sum += j;
			if (min == 0)
				min = i;
		}
	}
}
int main() {
	int m, n;
	scanf("%d\n%d", &m, &n);
	sosu(m, n);
	if (sum == 0)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, min);
	return 0;
}