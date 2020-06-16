#include<iostream>
#include<algorithm>
using namespace std;
#pragma warning(disable:4996)

struct Consulting {
	int day, pay;
};

int cache[16];

int main() {
	Consulting consul[16];
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &consul[i].day, &consul[i].pay);
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		if (i + consul[i].day <= n) {
			cache[i + consul[i].day] = max(cache[i + consul[i].day], cache[i] + consul[i].pay);
			result = max(result, cache[i + consul[i].day]);
		}
		cache[i + 1] = max(cache[i + 1], cache[i]);
		result = max(cache[i + 1], result);
	}
	printf("%d", result);
	return 0;
}