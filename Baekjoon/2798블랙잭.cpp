#include<iostream>
using namespace std;
int card[101];
int n, m;

int getSum() {
	int min = 987654321;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				if (card[i] + card[j] + card[k] <= m) {
					if (min > m - (card[i] + card[j] + card[k])) {
						min = m - (card[i] + card[j] + card[k]);
					}
				}
			}
		}
	}
	return m - min;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	cout << getSum();
	return 0;
}