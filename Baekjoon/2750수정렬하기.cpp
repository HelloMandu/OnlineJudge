#include<stdio.h>
#pragma warning(disable:4996)
int arr[1000];
int main() {
	int n;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}