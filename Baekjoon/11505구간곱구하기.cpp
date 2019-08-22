#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define MOD 1000000007
using namespace std;
typedef long long lint;

int n, m, k;
int num[1000001];
vector<lint> tree;

lint init(int node = 1, int start = 0, int end = n - 1) {
	if (start == end) {
		return tree[node] = num[start];
	}
	return tree[node] = (init(node * 2, start, (start + end) / 2) * init(node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

lint update(int index, lint changed, int node = 1, int start = 0, int end = n - 1) {
	if (index < start || index > end) {
		return tree[node];
	}
	else if (start == end) {
		return tree[node] = changed;
	}
	return tree[node] = update(index, changed, node * 2, start, (start + end) / 2) * update(index, changed, node * 2 + 1, (start + end) / 2 + 1, end) % MOD;
}

lint multiply(int left, int right, int node = 1, int start = 0, int end = n - 1) {
	if (right < start || left > end) {
		return 1;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	return (multiply(left, right, node * 2, start, (start + end) / 2) * multiply(left, right, node * 2 + 1, (start + end) / 2 + 1, end)) % MOD;
}

int main() {
	cin >> n >> m >> k;
	int height = (int)ceil(log2(n));
	tree.resize((int)pow(2, height + 1));
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	init();
	m += k;
	while (m--) {
		lint a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			update(b - 1, c);
		}
		else {
			cout << multiply(b - 1, c - 1) << '\n';
		}
	}
}