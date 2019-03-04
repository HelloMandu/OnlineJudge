#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 501
using namespace std;

int arr[MAX], cache[MAX], n;

/*arr[start]에서 시작하는 증가 부분 수열 중 최대길이를 반환*/
int lis(int start = -1) {
	/*메모이제이션*/
	int &ret = cache[start + 1];
	if (ret) {
		return ret;
	}
	ret = 1; // 항상 arr[start]를 포함하기 때문에 1
	for (int next = start + 1; next < n; next++) {
		/*arr[start]보다 뒤에 있고, 큰 수들 중 하나를 다음 숫자로 결정 후 부분 증가 수열의 최대치를 구함*/
		if (start == -1 || arr[start] < arr[next]) {
			ret = max(ret, lis(next) + 1);
		}
	}
	return ret;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		cout << lis() - 1 << '\n';
		memset(cache, 0, sizeof(cache));
	}
	return 0;
}