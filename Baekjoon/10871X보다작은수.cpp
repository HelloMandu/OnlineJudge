#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996)

int main() {
	int n, x;
	int num;
	scanf("%d %d", &n, &x);
	int *arr = (int*)malloc(sizeof(int)*n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &num);
		arr[i] = num;
	}
	for(int i = 0; i < n; i++)
	{
		if (arr[i] < x)
			printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}