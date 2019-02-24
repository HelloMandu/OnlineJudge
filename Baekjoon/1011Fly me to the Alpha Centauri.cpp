#include<iostream>
#include<cmath>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

typedef long long lint;

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		lint start, end;
		cin >> start >> end;
		lint dist = end - start; // ���� �̵��� �Ÿ�
		lint jump = 1;
		while (jump * jump <= dist) {
			jump++;
		}
		jump--;
		lint left = dist - (jump * jump);
		left = (lint)ceil((double)left / jump); // ���� �Ÿ����� �ְ�ӵ��� ������ �߰��Ÿ����
		cout << jump * 2 - 1 + left << '\n';
	}
	return 0;
}