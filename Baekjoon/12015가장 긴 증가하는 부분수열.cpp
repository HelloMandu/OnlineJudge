#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int num[1000001];
vector<int> lis;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	lis.push_back(-1);
	for (int i = 0; i < n; i++) {
		if (lis.back() < num[i]) {
			lis.push_back(num[i]);
		}
		else {
			auto it = lower_bound(lis.begin(), lis.end(), num[i]); // key값이 없으면 key값 이상의 수 중에서 가장 작은 정수값의 주소를 반환
			*it = num[i];
		}
	}
	cout << lis.size() - 1;
	return 0;
}