#include<iostream>
using namespace std;

int arr[10];
//int cnt[1000000001][10];
//bool cache[1000000001];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	long long n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num = i;
		while (num != 0) {
			arr[num % 10]++;
			num /= 10;
		}
	}
	for (int i = 0; i < 10; i++) {
		cout << arr[i] << ' ';
	}
	return 0;
}