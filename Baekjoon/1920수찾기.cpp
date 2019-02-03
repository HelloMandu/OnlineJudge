#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<int> arr;
	int n, num;
	cin >> n;
	arr.reserve(n);
	while (n--) {
		cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
	cin >> n;
	while (n--) {
		cin >> num;
		cout << binary_search(arr.begin(), arr.end(), num) ? 1 : 0;
		cout << '\n';
	}
	return 0;
}