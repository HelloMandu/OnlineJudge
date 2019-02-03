#include<iostream>
#include<algorithm>
#define MAX 301
using namespace std;

int stair[MAX]; // �� ����� ����
int dp[MAX]; // �ش� ��ܱ��� �����µ� �ɸ��� �ִ� ����

int MaxScore(int n) {
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]); // 1->3 �Ǵ� 2->3�� ū ���

	for (int i = 3; i < n; i++)
		dp[i] = max(dp[i - 2] + stair[i], dp[i - 3] + stair[i - 1] + stair[i]);
	return dp[n - 1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];
	cout << MaxScore(n);
	return 0;
}