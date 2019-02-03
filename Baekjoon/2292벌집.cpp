#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int n, temp = 1;
	int cnt;
	scanf("%d", &n);
	for (cnt = 1; temp < n; cnt++) {
		temp += 6 * cnt;
	}
	printf("%d\n", cnt);
	return 0;
}