#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int parent[201];

int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = getParent(parent[n]);
}

void unionParent(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) { parent[b] = a; }
	else { parent[a] = b; }
}

bool canTravel(int m) {
	int root;
	scanf("%d", &root);
	root = getParent(root);
	for (int i = 1; i < m; i++) {
		int loc;
		scanf("%d", &loc);
		if (root != getParent(loc)) {
			return false;
		}
	}
	return true;
}

int main() {
	int n, m;
	scanf("%d\n%d\n", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int isJoin;
			scanf("%d", &isJoin);
			if (isJoin) {
				unionParent(i, j);
			}
		}
	}
	printf("%s", (canTravel(m) ? "YES" : "NO"));
	return 0;
}