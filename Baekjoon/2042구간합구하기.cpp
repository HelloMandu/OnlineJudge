#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;

typedef long long lint;

int n, m, k;
lint num[1000001];
vector<lint> tree;

/*세그먼트 트리 생성*/
lint init(int node = 1, int start = 0, int end = n - 1) {
	if (start == end) {
		return tree[node] = num[start];
	}
	return tree[node] = init(node * 2, start, (start + end) / 2) + init(node * 2 + 1, (start + end) / 2 + 1, end);
}

/*세그먼트 트리 업데이트*/
void update(int index, lint diff, int node = 1, int start = 0, int end = n - 1) {
	if (index < start || index > end) {
		return;
	}
	tree[node] += diff;
	if (start != end) {
		update(index, diff, node * 2, start, (start + end) / 2);
		update(index, diff, node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

/*세그먼트 트리 구간합*/
lint sum(int left, int right, int node = 1, int start = 0, int end = n - 1) {
	if (left > end || right < start) {
		return 0;
	}
	else if (left <= start && end <= right) {
		return tree[node];
	}
	return sum(left, right, node * 2, start, (start + end) / 2) + sum(left, right, node * 2 + 1, (start + end) / 2 + 1, end);
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int height = (int)ceil(log2(n));
	tree.resize(pow(2, height + 1));
	init();
	int count = m + k;
	while (count--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c - num[b - 1];
			num[b - 1] = c;
			update(b - 1, diff);
		}
		else {
			cout << sum(b - 1, c - 1) << '\n';
		}
	}
	return 0;
}