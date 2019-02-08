#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			cout << ' ';
		}
		cout << '*';
		for (int k = 0; k < 2 * i - 1; k++) {
			if (i == n - 1) {
				cout << '*';
			}
			else {
				cout << ' ';
			}
		}
		if (i != 0) {
			cout << '*';
		}
		cout << '\n';
	}
	return 0;
}