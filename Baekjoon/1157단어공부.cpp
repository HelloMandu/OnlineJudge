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
		if ('a' <= voca[i] && voca[i] <= 'z') // 소문자를 숫자로
			n = voca[i] - 'a';
		else if ('A' <= voca[i] && voca[i] <= 'Z') // 대문자를 숫자로
			n = voca[i] - 'A';

		alphbet[n]++; // 해당위치 +1

		if (max < alphbet[n]) { // 갱신될때
			max = alphbet[n];
			result = n + 'A';
		}
		else if (max == alphbet[n]) // 같을때
			result = '?';
	}
	printf("%c\n", result);
	return 0;
}