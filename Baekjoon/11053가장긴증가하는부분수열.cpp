#include<iostream>
#include<algorithm>
using namespace std;

int arr[1001];
int cache[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				cache[i] = max(cache[i], cache[j]);
			}
		}
		cache[i] += 1;
		result = max(result, cache[i]);
	}
	cout << result;
	return 0;
}