#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[40001];
vector<int> result;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	result.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (arr[i] > result.back()) {
			result.push_back(arr[i]);
		}
		else {
			vector<int>::iterator it = lower_bound(result.begin(), result.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << result.size() - 1;
	return 0;
}