#include<iostream>
#define MAX 1001
using namespace std;

double MinCost(int sum[], int n, int l) {
	double result = MAX, average;
	for (int i = 0; i <= n - l; i++) {
		for (int j = i + l; j <= n; j++) {
			average = ((double)(sum[j] - sum[i]) / (j - i)); // 평균을 계산
			if (result > average) { // 최솟값 갱신
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
			sum[i] = sum[i - 1] + day; // 1부터 i까지의 합을 저장
		}
		cout.setf(ios::fixed);
		cout.precision(11);
		cout << MinCost(sum, n, l) << '\n';
	}
	return 0;
}