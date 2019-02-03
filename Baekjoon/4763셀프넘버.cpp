#include<stdio.h>
#pragma warning(disable :4996)
int n[10001];
int dn(int i) {
	int real = i;
	if (i >= 10000) {
		real += i / 10000;
		i %= 10000;
	}
	if (i >= 1000) {
		real += i / 1000;
		i %= 1000;
	}
	if (i >= 100) {
		real += i / 100;
		i %= 100;
	}
	if (i >= 10) {
		real += i / 10;
		real += i % 10;
	}
	if (i < 10)
			return real + i;

	return real;
}
int main() {
	for (int i = 1; i <= 10000; i++) {
		n[dn(i)] = 1;
		if (!n[i])
			printf("%d\n", i);
	}
	return 0;
}