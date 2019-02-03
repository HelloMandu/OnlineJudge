#include<stdio.h>
#pragma warning(disable :4996)

int main() {
int n, sum = 0;
char inp[101];
scanf("%d", &n);
scanf("%s", &inp);
for (int i = 0; i < n; i++) {
sum += inp[i]-48;
}
printf("%d\n", sum);
return 0;
}
/*int main() {
	int n, inp, sum = 0;
	scanf("%d", &n);
	scanf("%d", &inp);
	while(n--) {
		sum += inp % 10;
		inp /= 10;
	}
	printf("%d\n", sum);
	return 0;
}*/