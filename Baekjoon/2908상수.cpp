#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable :4996)

int main() {
	int result1 = 0, result2 = 0;
	int n1, n2;
	scanf("%d %d", &n1, &n2);
	while (n1 != 0) {
		result1 = result1 * 10 + n1 % 10;
		n1 /= 10;
	}
	while (n2 != 0) {
		result2 = result2 * 10 + n2 % 10;
		n2 /= 10;
	}
	
	printf("%d\n", (result1 > result2) ? result1 : result2);
	return 0;
}