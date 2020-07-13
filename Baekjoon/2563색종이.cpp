#include<iostream>
using namespace std;

int arr[101][101];

int main() {
	int n, result = 0;
	cin >> n;
	while (n--) {
		int x, y;
		cin >> x >> y;
		for (int i = x; i < x + 10; i++) {
			for (int j = y; j < y + 10; j++) {
				if (arr[i][j] == 0) {
					arr[i][j] = 1;
					result++;
				}
			}
		}
	}
	cout << result;
	return 0;
}