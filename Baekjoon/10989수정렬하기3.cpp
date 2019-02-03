#include <iostream>
#include <cstring>
#define MAX 10001
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int arr[MAX] = { 0 };
	int n, num;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		arr[num]++;
	}
	for (int i = 1; i < MAX; i++) {
		if (arr[i] > 0) {
			for (int j = 0; j < arr[i]; j++)
				cout << i << '\n';
		}
	}
	return 0;
}