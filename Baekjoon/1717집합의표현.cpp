#include<iostream>
using namespace std;
#pragma warning(disable:4996)

int parent[1000001];

int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = getParent(parent[n]);
}

void unionFind(int a, int b) {
	a = getParent(a);
	b = getParent(b);
	if (a < b) { parent[b] = a; }
	else { parent[a] = b; }
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}
	while (m--) {
		int type, a, b;
		scanf("%d %d %d", &type, &a, &b);
		if (!type) {
			unionFind(a, b);
		}
		else {
			printf("%s\n", (getParent(a) == getParent(b) ? "YES" : "NO"));
		}
	}
	return 0;
}