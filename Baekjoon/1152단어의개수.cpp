#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

int main() {
	char str[1000002];
	char *word;
	int cnt = 0;
	fgets(str, sizeof(str), stdin);
	word = strtok(str, " "); // ���ڿ��� ���ڷ� �ڸ��� �Լ�
	while (word != NULL) {
		cnt++;
		word = strtok(NULL, " ");
	}
	printf("%d\n", cnt);
	return 0;
}