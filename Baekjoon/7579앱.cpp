#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct App {
	int memory, cost;
};

App app[101];
int cache[10001];

int main() {
	memset(cache, -1, sizeof(cache));
	int n, memory;
	cin >> n >> memory;
	for (int i = 1; i <= n; i++) {
		cin >> app[i].memory;
	}
	for (int i = 1; i <= n; i++) {
		cin >> app[i].cost;
	}
	for (int i = 1; i <= n; i++) {
		int cost = app[i].cost;
		for (int j = 10000; j >= cost; j--) {
			if (cache[j - cost] != -1) {
				cache[j] = max(cache[j], cache[j - cost] + app[i].memory);
			}
		}
		cache[cost] = max(cache[cost], app[i].memory);
	}
	for (int i = 0; i <= 10001; i++) {
		if (cache[i] >= memory) {
			cout << i;
			break;
		}
	}
	return 0;
}