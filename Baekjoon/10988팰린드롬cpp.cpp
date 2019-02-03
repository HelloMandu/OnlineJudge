#include<stdio.h>
#include<string.h>
#pragma warning(disable :4996);

int result(char pdrop[]);

int main() {

	char pdrop[100]; //배열
	scanf("%s", pdrop);
	printf("%d\n", result(pdrop));

	return 0;
}

int result(char pdrop[]) {

	int n = strlen(pdrop); //배열길이

	for (int i = 0; i < n / 2; i++)
	{
		if (pdrop[i] != pdrop[n - (i + 1)])
			return 0;
	}

	return 1;
}