#include<stdio.h>
#pragma warning(disable:4996)

int main() {
	int N, num, cnt = 0;
	int i;
	scanf("%d", &N);
 	while (N--) {
		scanf("%d", &num);
		if (num == 1) continue;
		for (i = 2; i < num; i++) {
			if (num % i == 0)
				break;
		}
		if (num == i) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}