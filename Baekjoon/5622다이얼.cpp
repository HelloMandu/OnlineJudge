#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

int main() {

	char alphabet[26] = { 0 };
	char voca[15];
	int num[10] = { 0 };
	int temp;
	int result = 0;

	scanf("%s", &voca);
	int vocalen = strlen(voca);

	for (int i = 0; i < vocalen; i++) {
		if ('A' <= voca[i] && voca[i] <= 'Z') {
			temp = voca[i] - 'A';
			alphabet[temp]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		if (i < 3 && alphabet[i] != 0)
			num[1] += alphabet[i];
		else if (i < 6 && alphabet[i] != 0)
			num[2] += alphabet[i];
		else if (i < 9 && alphabet[i] != 0)
			num[3] += alphabet[i];
		else if (i < 12 && alphabet[i] != 0)
			num[4] += alphabet[i];
		else if (i < 15 && alphabet[i] != 0)
			num[5] += alphabet[i];
		else if (i < 19 && alphabet[i] != 0)
			num[6] += alphabet[i];
		else if (i < 22 && alphabet[i] != 0)
			num[7] += alphabet[i];
		else if (i < 26 && alphabet[i] != 0)
			num[8] += alphabet[i];
	}
	for (int i = 0; i < 10; i++) {
		if (num[i] != 0)
			result += (2 + i)*num[i];
	}
	printf("%d\n", result);
	return 0;
}