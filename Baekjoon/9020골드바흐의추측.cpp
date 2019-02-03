#include<iostream>
#define MAX 10001
using namespace std;

bool primeNumber[MAX];
/*�����佺�׳׽��� ü�� �̿��� �Ҽ��Ǻ�*/
void Eratostheness() {
	for (int i = 2; i * i < MAX; i++) {
		if (!primeNumber[i]) { // �Ҽ��� �ƴ� ���
			for (int j = 2; i*j < MAX; j++) {
				primeNumber[i*j] = true; // �Ҽ��� ����� ��� �Ҽ��� �ƴ�
			}
		}
	}
}
/*�� �Ҽ��� ���� �ּ��� �Ҽ��� ���*/
void GoldBach(int n) {
	for (int i = n / 2, j = n / 2; j <= n; i--, j++) { // �߰� ������ �� ���� ���� ���� Ŀ������
		if (!primeNumber[i] && !primeNumber[j]) { // �� ���� ��� �Ҽ��� �ƴ� ��
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