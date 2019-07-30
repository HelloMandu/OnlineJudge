#include<iostream>
#include<algorithm>
#include<cstring>
#define INFINITY 987654321
using namespace std;

struct Matrix {
	int y, x;
};

Matrix matrix[501];
unsigned int cache[501][501];

unsigned int solution(int start, int end) {
	unsigned int &ret = cache[start][end];
	if (ret != -1) {
		return ret;
	}
	else if (start == end) {
		return ret = 0;
	}
	unsigned int result = INFINITY;
	for (int i = start; i < end; i++) {
		result = min(result, solution(start, i) + solution(i + 1, end) + matrix[start].y * matrix[i].x * matrix[end].x);
	}
	return ret = result;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> matrix[i].y >> matrix[i].x;
	}
	memset(cache, -1, sizeof(cache));
	cout << solution(0, n - 1);
	return 0;
}