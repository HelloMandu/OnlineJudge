#include<iostream>
#include<algorithm>
using namespace std;

class MakeOne {
private:
	int n;
	int cache[1000001] = { 0 };
public:
	void SetN() {
		cin >> n;
	}
	void GetMinCase() {
		cache[1] = 0; cache[2] = 1; cache[3] = 1; // �ּ��� ���
		for (int i = 4; i <= n; i++) {
			cache[i] = cache[i - 1] + 1; // 1�� �� ���
			if (i % 3 == 0) // 3���� ������ �������� ���
				cache[i] = min(cache[i], cache[i / 3] + 1); // 1�� �����, 3���� ���� ���� ��
			else if (i % 2 == 0) // 2�� ������ �������� ���
				cache[i] = min(cache[i], cache[i / 2] + 1);
		}
		cout << cache[n];
	}
};

int main() {
	MakeOne *makeOne = new MakeOne;
	makeOne->SetN();
	makeOne->GetMinCase();
	return 0;
}