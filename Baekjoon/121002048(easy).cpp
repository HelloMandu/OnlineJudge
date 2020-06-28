#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

int getResult(int matrix[][21], int n, int depth) {
	if (depth == 5) {
		int result = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				result = max(result, matrix[i][j]);
			}
		}
		return result;
	}
	queue<int> Queue;
	int arr1[21][21];
	memset(arr1, 0, sizeof(arr1));
	for (int c = 0; c < n; c++) {
		for (int r = 0; r < n; r++) {
			if (matrix[r][c] != 0) {
				Queue.push(matrix[r][c]);
			}
		}
		int idx = 0;
		while (!Queue.empty()) {
			int first, second = 0;
			first = Queue.front(); Queue.pop();
			if (!Queue.empty()) { second = Queue.front(); }
			if (first == second) {
				arr1[idx++][c] = first + second;
				Queue.pop();
			}
			else {
				arr1[idx++][c] = first;
			}
		}
	}
	int arr2[21][21];
	memset(arr2, 0, sizeof(arr2));
	for (int r = 0; r < n; r++) {
		for (int c = n - 1; c >= 0; c--) {
			if (matrix[r][c] != 0) {
				Queue.push(matrix[r][c]);
			}
		}
		int idx = n - 1;
		while (!Queue.empty()) {
			int first, second = 0;
			first = Queue.front(); Queue.pop();
			if (!Queue.empty()) { second = Queue.front(); }
			if (first == second) {
				arr2[r][idx--] = first + second;
				Queue.pop();
			}
			else {
				arr2[r][idx--] = first;
			}
		}
	}
	int arr3[21][21];
	memset(arr3, 0, sizeof(arr3));
	for (int c = 0; c < n; c++) {
		for (int r = n - 1; r >= 0; r--) {
			if (matrix[r][c] != 0) {
				Queue.push(matrix[r][c]);
			}
		}
		int idx = n - 1;
		while (!Queue.empty()) {
			int first, second = 0;
			first = Queue.front(); Queue.pop();
			if (!Queue.empty()) { second = Queue.front(); }
			if (first == second) {
				arr3[idx--][c] = first + second;
				Queue.pop();
			}
			else {
				arr3[idx--][c] = first;
			}
		}
	}
	int arr4[21][21];
	memset(arr4, 0, sizeof(arr4));
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			if (matrix[r][c] != 0) {
				Queue.push(matrix[r][c]);
			}
		}
		int idx = 0;
		while (!Queue.empty()) {
			int first, second = 0;
			first = Queue.front(); Queue.pop();
			if (!Queue.empty()) { second = Queue.front(); }
			if (first == second) {
				arr4[r][idx++] = first + second;
				Queue.pop();
			}
			else {
				arr4[r][idx++] = first;
			}
		}
	}

	int a = getResult(arr1, n, depth + 1),
		b = getResult(arr2, n, depth + 1),
		c = getResult(arr3, n, depth + 1),
		d = getResult(arr4, n, depth + 1);
	return max(a, max(b, max(c, d)));
}


int main() {
	int n;
	int matrix[21][21];
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}
	cout << getResult(matrix, n, 0);
	return 0;
}
