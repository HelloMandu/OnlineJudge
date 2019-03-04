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

	/*난이도 1 : 모든 숫자가 같을 떄*/
	if (M == string(M.size(), M[0])) {
		return 1;
	}

	/*난이도 2 : 숫자가 1씩 단조증가 또는 단조감소*/
	bool progressive = true;
	for (int i = 0; i < M.size() - 1; i++) {
		if (M[i + 1] - M[i] != M[1] - M[0]) {
			progressive = false;
		}
	}
	if (progressive && abs(M[1] - M[0]) == 1) {
		return 2;
	}

	/*난이도 4 : 두개의 숫자가 번갈아 가며 감소*/
	bool alternating = true;
	for (int i = 0; i < M.size(); i++) {
		if (M[i] != M[i % 2]) {
			alternating = false;
		}
	}
	if (alternating) {
		return 4;
	}

	/*난이도 5 : 등차수열*/
	if (progressive) {
		return 5;
	}

	/*난이도 10*/
	return 10;
}

/*수열을 외우는 방법 중 최소난이도를 반환*/
int memorize(int begin = 0) {
	/*기저사례 : 문자열 끝에 도달 시*/
	if (begin == N.size()) {
		return 0;
	}
	/*메모이제이션*/
	int &ret = cache[begin];
	if (ret) {
		return ret;
	}
	/*3 ~ 5 중 최소의 난이도 계산*/
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