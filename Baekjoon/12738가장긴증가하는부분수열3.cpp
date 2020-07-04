#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int arr[1000001];
int lis = 0;
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> result;
	result.push_back(-1000000001);
	for (int i = 0; i < n; i++) {
		if (result.back() < arr[i]) {
			result.push_back(arr[i]);
			lis++;
		}
		else {
			vector<int>::iterator it = lower_bound(result.begin(), result.end(), arr[i]);
			*it = arr[i];
		}
	}
	cout << lis << '\n';
	return 0;
}