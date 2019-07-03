#include<iostream>
#include<algorithm>
#define MAX 301
using namespace std;

int stair[MAX]; // �� ����� ����
int cache[MAX]; // �ش� ��ܱ��� �����µ� �ɸ��� �ִ� ����

int MaxScore(int n) {
	cache[0] = stair[0];
	cache[1] = stair[0] + stair[1];
	cache[2] = max(stair[0] + stair[2], stair[1] + stair[2]); // 1->3 �Ǵ� 2->3�� ū ���

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