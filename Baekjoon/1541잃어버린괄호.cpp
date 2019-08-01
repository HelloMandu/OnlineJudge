#include<iostream>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;

int n, result = 0;
bool isMinus;
int main() {
	while (scanf("%d", &n) != EOF) {
		if (n < 0) {
			isMinus = true;
		}
		if (isMinus) {
			result -= abs(n);
		}
		else {
			result += abs(n);
		}
	}
	printf("%d", result);
	return 0;
}