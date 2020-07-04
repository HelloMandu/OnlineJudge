#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int arr[1001];
int result[1001];
int pre[1001];
int lis = 0;
int maxIdx = 0;
void printLis(int idx) {
	if (idx == -1) {

		return;
	}
	printLis(pre[idx]);
	cout << arr[idx] << ' ';
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	memset(pre, -1, sizeof(pre));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && result[i] < result[j]) {
				result[i] = result[j];
				pre[i] = j;
			}
		}
		if (result[i] == lis) {
			lis = result[i] + 1;
			maxIdx = i;
		}
		result[i] += 1;
	}
	cout << lis << '\n';
	printLis(maxIdx);
	return 0;
}