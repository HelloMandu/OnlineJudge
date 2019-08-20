#include<iostream>
#include<algorithm>
using namespace std;

long long n, c;
long long x[200001];
long long result = 0;
int main() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x + n);
	long long start = 0, finish = x[n - 1] - x[0];
	while (start <= finish) {
		long long mid = (start + finish) / 2;
		long long count = 1; // 공유기설치수
		long long wifi = x[0];
		for (int i = 1; i < n; i++) {
			if (x[i] - wifi >= mid) {
				count++; // 설치된 공유기
				wifi = x[i]; // 최근 설치 지점
			}
		}
		if (count < c) {
			finish = mid - 1;
		}
		else {
			result = max(result, mid);
			start = mid + 1;
		}
	}
	cout << result;
	return 0;
}