#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101
using namespace std;

int n, m, A[MAX], B[MAX], cache[MAX][MAX];
/*�Է��� 32��Ʈ ��ȣ�ִ� ������ ��� ���� ���� �� �����Ƿ� �������� �ּ�ġ�� 64��Ʈ�����Ѵ�*/
const long long NEGINF = numeric_limits<long long>::min();

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
}

int jlis(int indexA = -1, int indexB = -1) {
	int &ret = cache[indexA + 1][indexB + 1];
	/*�޸������̼�*/
	if (ret) {
		return ret;
	}
	/*A[indexA], B[indexB]�� �����ϹǷ� 2���� �׻�����*/
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	/*�������Ҹ� ã�´�*/
	for (int nextA = indexA + 1; nextA < n; nextA++) {
		if (maxElement < A[nextA]) {
			ret = max(ret, jlis(nextA, indexB) + 1);
		}
	}
	for (int nextB = indexB + 1; nextB < m; nextB++) {
		if (maxElement < B[nextB]) {
			ret = max(ret, jlis(indexA, nextB) + 1);
		}
	}

	return ret;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		input();
		cout << jlis() - 2 << '\n';
		memset(cache, 0, sizeof(cache));
	}
	return 0;
}