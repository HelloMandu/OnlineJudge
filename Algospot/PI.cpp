#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 10001
using namespace std;

string N;
int cache[MAX];

int classify(int start, int end) {
	string M = N.substr(start, end - start);

	/*���̵� 1 : ��� ���ڰ� ���� ��*/
	if (M == string(M.size(), M[0])) {
		return 1;
	}

	/*���̵� 2 : ���ڰ� 1�� �������� �Ǵ� ��������*/
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; i++) {
		if (M[i + 1] - M[i] != M[1] - M[0]) {
			progressive = false;
		}
	}
	if (progressive && abs(M[1] - M[0]) == 1) {
		return 2;
	}

	/*���̵� 4 : �ΰ��� ���ڰ� ������ ���� ����*/
	bool alternating = true;
	for (int i = 0; i < M.size(); i++) {
		if (M[i] != M[i % 2]) {
			alternating = false;
		}
	}
	if (alternating) {
		return 4;
	}

	/*���̵� 5 : ��������*/
	if (progressive) {
		return 5;
	}

	/*���̵� 10*/
	return 10;
}

/*������ �ܿ�� ��� �� �ּҳ��̵��� ��ȯ*/
int memorize(int begin = 0) {
	/*������� : ���ڿ� ���� ���� ��*/
	if (begin == N.size()) {
		return 0;
	}
	/*�޸������̼�*/
	int &ret = cache[begin];
	if (ret) {
		return ret;
	}
	/*3 ~ 5 �� �ּ��� ���̵� ���*/
	ret = 987654321;
	for (int L = 3; L <= 5; L++) {
		if (begin + L <= N.size()) {
			ret = min(ret, classify(begin, begin + L) + memorize(begin + L));
		}
	}

	return ret;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> N;
		cout << memorize() << '\n';
		memset(cache, 0, sizeof(cache));
	}
	return 0;
}