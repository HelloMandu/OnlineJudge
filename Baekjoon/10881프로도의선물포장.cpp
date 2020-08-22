#include<iostream>
#include<algorithm>
using namespace std;


int testcase;
int a[6], b[6];

int typeA(int i, int j, int k) {
	int la = a[i] + a[j] + a[k];
	int lb = max({ b[i], b[j], b[k] });
	return la * lb;
}

int typeB(int i, int j, int k) {
	int la = max(a[i] + a[j], a[k]);
	int lb = max(b[i], b[j]) + b[k];
	return la * lb;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> testcase;
	while (testcase--) {
		for (int i = 0; i < 3; i++) {
			cin >> a[i] >> a[i + 3];
			b[i] = a[i + 3];
			b[i + 3] = a[i];
		}
		int result = 987654321;
		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 6; j++) {
				for (int k = 0; k < 6; k++) {
					if (i % 3 != j % 3 && i % 3 != k % 3 && j % 3 != k % 3) {
						result = min({ result, typeA(i, j, k), typeB(i, j, k) });
					}
				}
			}
		}
		cout << result << '\n';
	}
	return 0;
}