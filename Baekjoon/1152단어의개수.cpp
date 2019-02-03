#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

int main() {
	char str[1000002];
	char *word;
	int cnt = 0;
	fgets(str, sizeof(str), stdin);
	word = strtok(str, " "); // 문자열을 문자로 자르는 함수
	while (word != NULL) {
		cnt++;
		word = strtok(NULL, " ");
	}
	printf("%d\n", cnt);
	return 0;
}