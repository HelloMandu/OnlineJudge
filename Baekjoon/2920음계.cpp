#include<stdio.h>
#pragma warning(disable :4996)

int main() {
	int eum[8] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int inp[8];
	int asc = 0, des = 0;
	for(int i = 0; i < 8; i++)
		scanf("%d", &inp[i]);
	for (int i = 0; i < 8; i++) {
		if (eum[i] == inp[i])
			asc++;
		else if (eum[8 - (i + 1)] == inp[i])
			des++;
	}
	if(asc == 8)
		printf("ascending\n");
	else if (des == 8)
		printf("descending\n");
	else
		printf("mixed\n");
	
	return 0;
}