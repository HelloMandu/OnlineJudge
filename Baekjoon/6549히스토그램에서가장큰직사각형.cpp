#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

int n;
int rectangle[100001];
vector<int> tree;

int init(int node = 1, int start = 0, int end = n - 1) {
	if (start == end) {
		return tree[node] = start;
	}
	int a = init(node * 2, start, (start + end) / 2);
	int b = init(node * 2 + 1, (start + end) / 2 + 1, end);
	return tree[node] = rectangle[a] < rectangle[b] ? a : b;
}

int query(int left, int right, int node = 1, int start = 0, int end = n - 1) {
	if (right < start || left > end) {
		return -1;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	int a = query(left, right, node * 2, start, (start + end) / 2);
	int b = query(left, right, node * 2 + 1, (start + end) / 2 + 1, end);
	if (a == -1) {
		return b;
	}
	else if (b == -1) {
		return a;
	}
	return rectangle[a] < rectangle[b] ? a : b;
}

long long getMaxRectangleSize(int start = 0, int end = n - 1) {
	int minIndex = query(start, end);
	long long result = (long long)(end - start + 1) * rectangle[minIndex];
	if (start < minIndex) {
		long long temp = getMaxRectangleSize(start, minIndex - 1);
		result = max(result, temp);
	}
	if (minIndex < end) {
		long long temp = getMaxRectangleSize(minIndex + 1, end);
		result = max(result, temp);
	}
	return result;
}

int main() {
	while (cin >> n) {
		if (n == 0) {
			return 0;
		}
		int height = (int)ceil(log2(n));
		tree.resize((int)pow(2, height + 1));
		for (int i = 0; i < n; i++) {
			cin >> rectangle[i];
		}
		init();
		cout << getMaxRectangleSize() << '\n';
		tree.clear();
	}
}