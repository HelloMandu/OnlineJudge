#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

char voca[1000000];
int alphbet[26];

int main() {
	int n, max = 0;
	char result;
	scanf("%s", &voca);

	for (int i = 0; voca[i] != NULL; i++) {
		if ('a' <= voca[i] && voca[i] <= 'z') // �ҹ��ڸ� ���ڷ�
			n = voca[i] - 'a';
		else if ('A' <= voca[i] && voca[i] <= 'Z') // �빮�ڸ� ���ڷ�
			n = voca[i] - 'A';

		alphbet[n]++; // �ش���ġ +1

		if (max < alphbet[n]) { // ���ŵɶ�
			max = alphbet[n];
			result = n + 'A';
		}
		else if (max == alphbet[n]) // ������
			result = '?';
	}
	printf("%c\n", result);
	return 0;
}