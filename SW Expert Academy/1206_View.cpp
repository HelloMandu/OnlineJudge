#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1004
using namespace std;

int buildings[MAX];

int getViewRights(int home) {
	int maxHeight = 0;
	for (int i = home - 2; i <= home + 2; i++) {
		if (i != home) {
			if (buildings[i] >= buildings[home]) {
				return 0;
			}
			maxHeight = max(maxHeight, buildings[i]);
		}
	}
	return  buildings[home] - maxHeight;
}

int getAllViewRights(int n) {
	int viewRights = 0;
	for (int i = 2; i < n - 2; i++) {
		viewRights += getViewRights(i);
	}
	return viewRights;
}

int main() {
	fastIO();
	int count = 10;
	for (int t = 1; t <= count; t++) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> buildings[i];
		}
		cout << '#' << t << ' ' << getAllViewRights(n) << '\n';
	}
	return 0;
}