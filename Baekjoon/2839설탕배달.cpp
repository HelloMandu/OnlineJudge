#include<stdio.h>
#pragma warning(disable :4996);

int main() {

	int n, remain; // n킬로그램, 5로 나눴을 때 나머지
	int x = 0, y = 0; // 3x + 5y = n

	scanf("%d", &n);
	y = n / 5;
	remain = n % 5;
	while (y >= 0)
	{
		if (remain % 3 == 0)
		{
			x = remain / 3;
			remain %= 3;
			break;
		}
		y--;
		remain += 5;
	}
	printf("%d\n", (remain == 0) ? (x + y) : -1);
	return 0;
}