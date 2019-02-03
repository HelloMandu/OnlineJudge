#include<iostream>
#define MAX 1001
using namespace std;

double MinCost(int sum[], int n, int l) {
	double result = MAX, average;
	for (int i = 0; i <= n - l; i++) {
		for (int j = i + l; j <= n; j++) {
			average = ((double)(sum[j] - sum[i]) / (j - i)); // ����� ���
			if (result > average) { // �ּڰ� ����
				result = average;
			}
		}
	}
	return result;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int sum[MAX] = { 0 };
		int day, n, l;
		cin >> n >> l;
		for (int i = 1; i <= n; i++) {
			cin >> day;
			sum[i] = sum[i - 1] + day; // 1���� i������ ���� ����
		}
		cout.setf(ios::fixed);
		cout.precision(11);
		cout << MinCost(sum, n, l) << '\n';
	}
	return 0;
}