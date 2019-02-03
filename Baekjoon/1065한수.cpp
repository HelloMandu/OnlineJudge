#include<stdio.h>
#pragma warning(disable :4996)

int main() {

	int n, cnt = 99;
	int hund, ten, one;
	scanf("%d", &n);

	if (n < 100) {
		cnt = n;
	}
	else{
		for (int i = 100; i <= n; i++)
		{

			hund = i / 100;
			ten = (i / 10) % 10;
			one = i % 10;
			if (hund - ten == ten - one)
				cnt++;
		}
}
	printf("%d", cnt);
	return 0;
}