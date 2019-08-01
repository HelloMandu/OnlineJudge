#include<iostream>
#include<algorithm>
using namespace std;

struct Stuff {
	int w, v;
};
int n, k;
Stuff stuff[101];
int knapsack[101][100001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> stuff[i].w >> stuff[i].v;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			knapsack[i][j] = knapsack[i - 1][j]; // 여유공간이 없을 시
			if (j - stuff[i].w >= 0) { // 여유공간이 있을 때
				knapsack[i][j] = max(knapsack[i - 1][j], knapsack[i][j - stuff[i].w] + stuff[i].v);
			}
		}
	}
	cout << knapsack[n][k];
	return 0;
}