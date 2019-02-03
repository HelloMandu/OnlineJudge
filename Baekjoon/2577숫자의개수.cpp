#include<stdio.h>
#pragma warning(disable :4996)
int main() {
	int a, b, c;
	int result, temp = 0;
	int print[10] = { 0 };
	scanf("%d %d %d", &a, &b, &c);
	result = a * b * c;
	while(1) {
		temp = (result % 10);
		print[temp]++;
		result /= 10;
		if(result == 0) break;
	}
	for (int i = 0; i < 10; i++)
		printf("%d\n", print[i]);
	return 0;
}