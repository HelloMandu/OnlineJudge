#include<iostream>
#define MAX 10001
using namespace std;

bool primeNumber[MAX];
/*에라토스테네스의 체를 이용해 소수판별*/
void Eratostheness() {
	for (int i = 2; i * i < MAX; i++) {
		if (!primeNumber[i]) { // 소수가 아닌 경우
			for (int j = 2; i*j < MAX; j++) {
				primeNumber[i*j] = true; // 소수의 배수는 모두 소수가 아님
			}
		}
	}
}
/*두 소수의 차가 최소인 소수를 출력*/
void GoldBach(int n) {
	for (int i = n / 2, j = n / 2; j <= n; i--, j++) { // 중간 값부터 두 수의 차가 점점 커지도록
		if (!primeNumber[i] && !primeNumber[j]) { // 두 수가 모두 소수가 아닐 때
			cout << i << ' ' << j << '\n';
			return;
		}
	}
}

int main() {
	Eratostheness();
	int testcase, n;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		GoldBach(n);
	}
	return 0;
}