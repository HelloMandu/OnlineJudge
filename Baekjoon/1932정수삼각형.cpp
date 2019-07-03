#include<iostream>
#include<algorithm>
#define MAX 501
using namespace std;

int triangle[MAX][MAX];
int cache[MAX][MAX];
int MaxRoute(int n, int i = 0, int j = 0) {
	if (i == n)
		return 0;
	else if (cache[i][j])
		return cache[i][j];
	else
		return cache[i][j] = max(MaxRoute(n, i + 1, j), MaxRoute(n, i + 1, j + 1)) + triangle[i][j];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i + 1; j++)
			cin >> triangle[i][j];
	cout << MaxRoute(n);
	return 0;
}