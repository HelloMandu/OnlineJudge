#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 101
using namespace std;

int n, m, A[MAX], B[MAX], cache[MAX][MAX];
/*입력이 32비트 부호있는 정수의 모든 값을 가질 수 있으므로 인위적인 최소치는 64비트여야한다*/
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
	/*메모이제이션*/
	if (ret) {
		return ret;
	}
	/*A[indexA], B[indexB]가 존재하므로 2개는 항상있음*/
	ret = 2;
	long long a = (indexA == -1 ? NEGINF : A[indexA]);
	long long b = (indexB == -1 ? NEGINF : B[indexB]);
	long long maxElement = max(a, b);

	/*다음원소를 찾는다*/
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