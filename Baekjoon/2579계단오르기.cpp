#include<iostream>
#include<algorithm>
#define MAX 301
using namespace std;

int stair[MAX]; // 각 계단의 점수
int cache[MAX]; // 해당 계단까지 오르는데 걸리는 최대 점수

int MaxScore(int n) {
	cache[0] = stair[0];
	cache[1] = stair[0] + stair[1];
	cache[2] = max(stair[0] + stair[2], stair[1] + stair[2]); // 1->3 또는 2->3중 큰 경우

	for (int i = 3; i < n; i++)
		cache[i] = max(cache[i - 2] + stair[i], cache[i - 3] + stair[i - 1] + stair[i]);
	return cache[n - 1];
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> stair[i];
	cout << MaxScore(n);
	return 0;
}