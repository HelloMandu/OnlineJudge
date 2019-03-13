#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1000000
using namespace std;

typedef long long lint;

int N, M, topheight = 0;
int trees[MAX];

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> trees[i];
		topheight = max(topheight, trees[i]);
	}
}

int getMaxHeight() {
	int start = 0, end = topheight;
	int result = 0, mid;
	while (start <= end) {
		lint allHeight = 0;
		mid = (end + start) / 2;
		for (int i = 0; i < N; i++) {
			if (trees[i] - mid > 0) { // �ڸ� �� ���� ��
				allHeight += trees[i] - mid; // �ڸ� ���̸� ������
			}
		}

		if (allHeight >= M) { // �� �ڸ� ���̰� �ּҳ��̸� �Ѿ ��
			start = mid + 1;
			result = max(result, mid); // �ڸ� �� �ִ� ������ �ִ��� ����
		}
		else { // �� �ڸ� ���̰� �ּҳ��� ������ ��
			end = mid - 1;
		}

	}
	return result;
}

int main() {
	fastIO();
	input();
	cout << getMaxHeight();
	return 0;
}