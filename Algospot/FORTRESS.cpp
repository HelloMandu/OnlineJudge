#include<iostream>
#include<vector>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101
using namespace std;

int n, y[MAX], x[MAX], radius[MAX];
int longest; // ���� �� ��-�� ����� ���̸� ��ȯ

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

/*�������� ���̰� ��ũ��, ���� ���ο� �ִ� ���*/
bool isIncluded(int parent, int child) {
	return radius[parent] > radius[child] && sqr(radius[parent] - radius[child]) > sqrdist(parent, child);
}

bool isChild(int parent, int child) {
	/*���Ե��� �ʴ� ���*/
	if (!isIncluded(parent, child)) {
		return false;
	}
	/*���������� �����ϴ� ���� �ƴ� ���*/
	for (int i = 0; i < n; i++) {
		if (i != parent && i != child && isIncluded(parent, i) && isIncluded(i, child)) {
			return false;
		}
	}
	return true;
}

/*Ʈ�� ����*/
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
	/*�� �ڽ��� ��Ʈ�� �ϴ� ����Ʈ���� ���̸� ���*/
	for (int i = 0; i < root->child.size(); i++) {
		heights.push_back(getHeight(root->child[i]));
	}
	/*�ڽ��� ���� �� 0�� ��ȯ*/
	if (heights.empty()) {
		return 0;
	}
	/*���̼����� ����*/
	sort(heights.begin(), heights.end());
	/*root�� �ֻ������� �ϴ� ��θ� ���*/
	if (heights.size() >= 2) {
		longest = max(longest, 2 + heights[heights.size() - 2] + heights[heights.size() - 1]);
	}
	/*����Ʈ�� ������ �ִ�ġ + 1*/
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