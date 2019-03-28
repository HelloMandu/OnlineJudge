#include<iostream>
#include<vector>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101
using namespace std;

int n, y[MAX], x[MAX], radius[MAX];
int longest; // 가장 긴 잎-잎 경로의 길이를 반환

struct Node {
	vector<Node*> child;
};

int sqr(int x) {
	return x * x;
}

/*r^2 = x^2 + y^2*/
int sqrdist(int a, int b) {
	return sqr(y[a] - y[b]) + sqr(x[a] - x[b]);
}

/*반지름의 길이가 더크고, 원이 내부에 있는 경우*/
bool isIncluded(int parent, int child) {
	return radius[parent] > radius[child] && sqr(radius[parent] - radius[child]) > sqrdist(parent, child);
}

bool isChild(int parent, int child) {
	/*포함되지 않는 경우*/
	if (!isIncluded(parent, child)) {
		return false;
	}
	/*직접적으로 포함하는 것이 아닌 경우*/
	for (int i = 0; i < n; i++) {
		if (i != parent && i != child && isIncluded(parent, i) && isIncluded(i, child)) {
			return false;
		}
	}
	return true;
}

/*트리 생성*/
Node *getTree(int root = 0) {
	Node *ret = new Node();
	for (int i = 0; i < n; i++) {
		if (isChild(root, i)) {
			ret->child.push_back(getTree(i));
		}
	}
	return ret;
}

int getHeight(Node *root) {
	vector<int> heights;
	/*각 자식을 루트로 하는 서브트리의 높이를 계산*/
	for (int i = 0; i < root->child.size(); i++) {
		heights.push_back(getHeight(root->child[i]));
	}
	/*자식이 없을 시 0을 반환*/
	if (heights.empty()) {
		return 0;
	}
	/*높이순으로 정렬*/
	sort(heights.begin(), heights.end());
	/*root를 최상위노드로 하는 경로를 계산*/
	if (heights.size() >= 2) {
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	}
	/*서브트리 높이의 최댓치 + 1*/
	return heights.back() + 1;
}

int getMaxRoute(Node *root) {
	longest = 0;
	int h = getHeight(root);
	return max(longest, h);
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> y[i] >> x[i] >> radius[i];
		}
		Node *root = getTree();
		cout << getMaxRoute(root) << '\n';
	}
	return 0;
}