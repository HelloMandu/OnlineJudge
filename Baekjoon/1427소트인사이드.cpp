#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


int compare(const void *a, const void *b) {
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 < num2)
		return 1;
	if (num1 > num2)
		return -1;
	return 0;
}
int main() {

	int n, cnt = 0;
	int arr[100000];
	scanf("%d", &n);

	for (int i = 0; n != 0; i++) {
		arr[i] = n % 10;
		n /= 10; cnt++;
	}
	qsort(arr, cnt, sizeof(int), compare);
	
	for (int i = 0; i < cnt; i++)
		printf("%d", arr[i]);
	printf("\n");
	return 0;
}