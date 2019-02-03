#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int main() {
	int t, n, result, max = 0;
	int num[10] = { 0 };

	scanf("%d", &t);

	while (t--) {
		scanf("%d", &n);
		num[n]++;
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] > max) {
			max = num[i];
			result = i;
		}
	}
	printf("%d\n", result);
}