#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996)

int main() {
	int t, r;
	char s[20] = { 0 };
	scanf("%d", &t);
	while (t--) {
		scanf("%d %s", &r, &s);
		for (int i = 0; s[i] != 0; i++) {
			for (int j = 0; j < r; j++)
				printf("%c", s[i]);
		}
		printf("\n");
	}

	return 0;
}