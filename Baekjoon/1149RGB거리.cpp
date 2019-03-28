#include<iostream>
#include<algorithm>
using namespace std;

int home[1001][3];
int cost[1001][3];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> home[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		cost[0][i] = home[0][i];
	}
	for (int i = 1; i <= n; i++) {
		cost[i][0] = min(cost[i - 1][1], cost[i - 1][2]) + home[i][0];
		cost[i][1] = min(cost[i - 1][0], cost[i - 1][2]) + home[i][1];
		cost[i][2] = min(cost[i - 1][0], cost[i - 1][1]) + home[i][2];
	}
	cout << min(min(cost[n][0], cost[n][1]), cost[n][2]);
	return 0;
}