#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int n;

int lis() {
	int cache1[1001] = { 0 };
	int cache2[1001] = { 0 };

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cache1[i] = max(cache1[i], cache1[j]);
			}
		}
		cache1[i] += 1;
	}
	for (int i = n - 1; i > -1; i--) {
		for (int j = n - 1; j > i; j--) {
			if (arr[i] > arr[j]) {
				cache2[i] = max(cache2[i], cache2[j]);
			}
		}
		cache2[i] += 1;
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		result = max(result, cache1[i] + cache2[i]);
	}
	return result - 1;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cout << lis();
	return 0;
}