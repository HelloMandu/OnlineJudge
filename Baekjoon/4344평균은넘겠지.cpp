#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable :4996)

int main() {
	int c, n;
	int sum = 0, avg;
	int cnt = 0;
	scanf("%d", &c);
	while (c--) {
		scanf("%d", &n);
		int *score = (int*)malloc(sizeof(int)*n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &score[i]);
			sum += score[i];
		}
		avg = sum / n;
		for (int i = 0; i < n; i++) {
			if (score[i] > avg) cnt++;
		}
		printf("%0.3lf%\n", ((double)cnt / n)*100);
		free(score);
		cnt = 0; sum = 0;
	}
	return 0;
}