#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fastIO();
	int n;
	bool check = false;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - (i + 1); j++) {
			cout << ' ';
		}
		cout << '*';
		for (int k = 0; k < 2 * i - 1; k++) {
			if (check) {
				cout << ' ';
			}
			else {
				cout << '*';
			}
			check = check ? false : true;
		}
		if (i != 0) {
			cout << '*';
		}
		cout << '\n';
		check = check ? false : true;
	}
	return 0;
}