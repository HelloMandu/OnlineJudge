#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

int main() {
	char str[101];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		printf("%c", str[i]);
		if ((i + 1) % 10 == 0)
			printf("\n");
	}
	return 0;
}