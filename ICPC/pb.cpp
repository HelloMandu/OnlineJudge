#include <cmath>
#include <iostream>
using namespace std;

int cache[50001];

int solve(int n) {
	for (int i = 1; i < n + 1; i++)
		for (int j = 1; j * j <= i; j++)
			if (cache[i] > cache[i - j * j] + 1 || cache[i] == 0)
				cache[i] = cache[i - j * j] + 1;
	return cache[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d", solve(n));
	return 0;
}