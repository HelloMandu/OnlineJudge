#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 21
using namespace std;

int cleck[MAX];
int N, B;
int result = 987654321;

void computeHeight(int present = 0, int allheight = 0) {
	/*������� : ���� index�� �ʰ� ���� ��*/
	if (present > N) {
		return;
	}
	/*������� : �������� Ű���� Ŭ ���*/
	else if (allheight >= B) {
		result = min(result, allheight);
	}
	/*���� index���� ������ index������ ��*/
	computeHeight(present + 1, cleck[present] + allheight);
	/*���� index�� �����ϰ� ������ index������ ��*/
	computeHeight(present + 1, allheight);
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		cin >> N >> B;
		for (int i = 0; i < N; i++) {
			cin >> cleck[i];
		}
		computeHeight();
		cout << '#' << t << ' ' << result - B << '\n';
		result = 987654321;
	}
	return 0;
}