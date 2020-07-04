#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Line {
	int left, right;
	bool operator<(const Line &A) {
		return left < A.left;
	}
};

vector<Line> arr;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		arr.push_back({ l, r });
	}
	sort(arr.begin(), arr.end());
	vector<int> result;
	result.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (result.back() < arr[i].right) {
			result.push_back(arr[i].right);
		}
		else {
			vector<int>::iterator it = lower_bound(result.begin(), result.end(), arr[i].right);
			*it = arr[i].right;
		}
	}
	cout << result.size() - 1;
	return 0;
}