#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100
using namespace std;
int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];
int n, m, k;
void inputMatrix() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> matrixA[i][j];
		}
	}
	cin >> m >> k;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cin >> matrixB[i][j];
		}
	}
}

void multipleMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			for (int k = 0; k < m; k++) {
				result[i][j] += matrixA[i][k] * matrixB[k][j];
			}
		}
	}
}

void outputMatrix() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cout << result[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main() {
	fastIO();
	inputMatrix();
	multipleMatrix();
	outputMatrix();
	return 0;
}