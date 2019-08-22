#include<iostream>
#include<algorithm>
using namespace std;

int n;
int rectangle[100001];

int getMinIndex(int start, int end) {
	int minIndex = start;
	for (int i = start + 1; i < end; i++) {
		if (rectangle[minIndex] > rectangle[i]) {
			minIndex = i;
		}
	}
	return minIndex;
}

int maxArea(int start = 0, int end = n) {
	if (start < end) {
		if (start == end - 1) {
			return rectangle[start];
		}
		int minIndex = getMinIndex(start, end);
		int result = rectangle[minIndex] * (end - start);
		result = max(result, max(maxArea(start, minIndex), maxArea(minIndex + 1, end)));
		return result;
	}
	return 0;
}

int main() {
	while (cin >> n) {
		if (n == 0) {
			return 0;
		}
		for (int i = 0; i < n; i++) {
			cin >> rectangle[i];
		}
		cout << maxArea() << '\n';
	}
}