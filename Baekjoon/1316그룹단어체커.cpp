#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)
char voca[100];
int alphbet[26];
int main() {
	int t, n, result, vocalen;
	scanf("%d", &t);
	result = t;
	while (t--) {
		scanf("%s", &voca);
		vocalen = strlen(voca);
			for (int i = 0; i < vocalen - 1; i++) {
				n = voca[i] - 'a';
				alphbet[n]++;
				if (voca[i] != voca[i + 1]) {
					n = voca[i + 1] - 'a';
					if (alphbet[n] != 0) {
						result--;
						break;
					}
				}
			}
			memset(alphbet, 0, sizeof(alphbet));
	}
	printf("%d\n", result);
	return 0;
}