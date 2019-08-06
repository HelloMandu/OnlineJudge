#include<iostream>
#include<algorithm>
using namespace std;

int n, m;
int arr[500001];

int findNum(int num) {
	return upper_bound(arr, arr + n, num) - lower_bound(arr, arr + n, num);
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int num;
		scanf("%d", &num);
		printf("%d ", findNum(num));
	}
	return 0;
}