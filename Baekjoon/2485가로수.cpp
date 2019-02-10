/*유클리드 호제법*/
#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int tree[100001];
int length[100001];

inline int getGcd(int tree1, int tree2) {
	return tree2 ? getGcd(tree2, tree1%tree2) : tree1;
}

int main() {
	fastIO();
	int n, gcd = 987654321;
	long long result = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tree[i];
		length[i] = tree[i] - tree[i - 1];
	}

	for (int i = 1; i < n; i++) {
		int temp = getGcd(length[i + 1], length[i]);
		gcd = min(gcd, temp);
	}

	for (int i = 1; i < n; i++) {
		result += length[i] / gcd - 1;
	}

	cout << result;
	return 0;
}