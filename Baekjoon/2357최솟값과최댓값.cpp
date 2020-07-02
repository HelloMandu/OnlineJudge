#include<iostream>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;

int *minTree, *maxTree;
int arr[100001];

void init(int root, int start, int end) {
	if (start == end) {
		minTree[root] = maxTree[root] = arr[start];
	}
	else {
		init(root * 2, start, (start + end) / 2);
		init(root * 2 + 1, (start + end) / 2 + 1, end);
		minTree[root] = min(minTree[root * 2], minTree[root * 2 + 1]);
		maxTree[root] = max(maxTree[root * 2], maxTree[root * 2 + 1]);
	}
}

int minimum(int tree[], int root, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return INT_MAX;
	}
	else if (left <= start && end <= right) {
		return tree[root];
	}
	return min(minimum(tree, root * 2, start, (start + end) / 2, left, right), minimum(tree, root * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int maximum(int tree[], int root, int start, int end, int left, int right) {
	if (left > end || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[root];
	}
	return max(maximum(tree, root * 2, start, (start + end) / 2, left, right), maximum(tree, root * 2 + 1, (start + end) / 2 + 1, end, left, right));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int height = (int)(ceil(log2(n)));
	int treeSize = 1 << (height + 1);
	minTree = new int[treeSize];
	maxTree = new int[treeSize];
	for (int i = 1; i <= treeSize; i++) {
		minTree[i] = INT_MAX;
	}
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	init(1, 0, n - 1);
	while (m--) {
		int left, right;
		cin >> left >> right;
		cout << minimum(minTree, 1, 0, n - 1, left - 1, right - 1) << ' ' << maximum(maxTree, 1, 0, n - 1, left - 1, right - 1) << '\n';
	}

	return 0;
}