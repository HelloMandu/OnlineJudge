#include<stdio.h>
#pragma warning(disable:4996)
int arr[1000001] = { 0, 1 };
int main() {

	int m, n;
	
	scanf("%d %d", &m, &n);
	
	for (int i = 2; i <= n; i++)
		for (int j = 2; i*j <= n; j++)
			arr[i*j] = 1; // �Ҽ��� �ƴ� ��� true

	for (int i = m; i <= n; i++)
		if (!arr[i]) // true�� �ƴ� �� ���
			printf("%d\n", i);

	return 0;
}