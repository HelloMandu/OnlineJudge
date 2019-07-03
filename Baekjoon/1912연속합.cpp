#include<iostream>
#define Max(a, b) a > b ? a : b
using namespace std;

typedef long long lint;
int arr[100001];
lint cache[100001];

lint MaxSum(int n) {
	cache[0] = arr[0]; // dp�� ó�� �κд����� ����
	lint max = cache[0]; // ������� �ʱ� ��
	for (int i = 1; i < n; i++) {
		cache[i] = Max(cache[i - 1] + arr[i], arr[i]); // dp�� ����� �κ� �����հ� ���� ���� ��
		max = Max(max, cache[i]); // �ִ밪 ����
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