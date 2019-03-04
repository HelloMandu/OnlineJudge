#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 501
using namespace std;

int arr[MAX], cache[MAX], n;

/*arr[start]���� �����ϴ� ���� �κ� ���� �� �ִ���̸� ��ȯ*/
int lis(int start = -1) {
	/*�޸������̼�*/
	int &ret = cache[start + 1];
	if (ret) {
		return ret;
	}
	ret = 1; // �׻� arr[start]�� �����ϱ� ������ 1
	for (int next = start + 1; next < n; next++) {
		/*arr[start]���� �ڿ� �ְ�, ū ���� �� �ϳ��� ���� ���ڷ� ���� �� �κ� ���� ������ �ִ�ġ�� ����*/
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