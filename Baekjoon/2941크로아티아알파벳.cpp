#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)

int result(char voca[]) {
	int result = 0;
	int vocalen = strlen(voca);

	for (int i = 0; i < vocalen; i++) {
		if (voca[i] == 'c') {
			if (voca[i + 1] == '=') { // "c="
				i++;
			}
			else if (voca[i + 1] == '-') { // "c-"
				i++;
			}
		}
		else if (voca[i] == 'd') {
			if (voca[i + 1] == 'z') {
				if (voca[i + 2] == '=') { // "dz="
					i += 2;
				}
			}
			else if (voca[i + 1] == '-') { // "d-"
				i++;
			}
		}
		else if (voca[i] == 'l') {
			if (voca[i + 1] == 'j') { // "lj"
				i++;
			}
		}
		else if (voca[i] == 'n') {
			if (voca[i + 1] == 'j') { // "nj"
				i++;
			}
		}
		else if (voca[i] == 's') {
			if (voca[i + 1] == '=') { //  "s="
				i++;
			}
		}
		else if (voca[i] == 'z') {
			if (voca[i + 1] == '=') { // "z="
				i++;
			}
		}
		result++;
	}
	return result;
}

int main() {
	char voca[101];
	
	scanf("%s", &voca);
	printf("%d\n", result(voca));

	return 0;
}