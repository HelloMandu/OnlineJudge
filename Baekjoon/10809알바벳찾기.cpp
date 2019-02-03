#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

int main() {
	char voca[100] = { 0 };
	char alphabet;
	int i;
	int temp = 0;
	scanf("%s", &voca);
	for (alphabet = 'a'; alphabet <= 'z'; alphabet++) {
		for (i = 0; voca[i] != 0; i++) {
			if (alphabet == voca[i]) {
				temp = 1;
				break;
			}
		}
		if (temp == 1)
			printf("%d ", i);
		else
			printf("-1 ");
		temp = 0;
	}
	return 0;
}