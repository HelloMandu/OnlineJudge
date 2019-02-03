#include<iostream>
using namespace std;

class Ball {
private:
	int n, m, l; // ��� ��, �������� Ƚ��, n-1���� �۰ų� ���� �ڿ���
	int people[1001] = { 0 }; // �� ����� �� ���� Ƚ��
	int count = 0; // ���� �� ���� Ƚ��
public:
	void SetBall() {
		cin >> n >> m >> l;
	}
	int GetResult() {
		int present = 1;
		people[present]++;
		while (people[present] < m) {
			count++; // ������
			if (people[present] % 2) // Ȧ�� �϶�
				present = (present + n - l) % n;
			else // ¦�� �϶�
				present = (present + l) % n;
			people[present]++; // ������ Ƚ��++
		}
		return count;
	}
};

int main() {
	Ball ball;
	ball.SetBall();
	cout << ball.GetResult();
	return 0;
}