#include<iostream>
#define Max(a, b) a > b ? a : b
using namespace std;

typedef long long lint;
int arr[100001];
lint dp[100001];

lint MaxSum(int n) {
	dp[0] = arr[0]; // dp에 처음 부분누적합 저장
	lint max = dp[0]; // 결과값의 초기 값
	for (int i = 1; i < n; i++) {
		dp[i] = Max(dp[i - 1] + arr[i], arr[i]); // dp에 저장된 부분 누적합과 현재 값을 비교
		max = Max(max, dp[i]); // 최대값 갱신
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << MaxSum(n);
	return 0;
}