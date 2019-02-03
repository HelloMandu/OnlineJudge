#include<stdio.h>
#pragma warning(disable :4996)
int main() {
	char *day[7] = { "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN" };
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int x, y; // ¿ù, ÀÏ
	int monthsum = 0;
	scanf("%d %d", &x, &y);
	for (int i = 0; i < x - 1; i++)
		monthsum += month[i];
	int n = (monthsum + y) % 7;
	if (n == 0) n = 7;
	printf("%s\n", day[n - 1]);
	return 0;
}