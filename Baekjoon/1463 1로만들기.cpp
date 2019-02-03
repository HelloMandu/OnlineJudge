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
		cache[1] = 0; cache[2] = 1; cache[3] = 1; // 최소의 경우
		for (int i = 4; i <= n; i++) {
			cache[i] = cache[i - 1] + 1; // 1을 뺀 경우
			if (i % 3 == 0) // 3으로 나누어 떨어지는 경우
				cache[i] = min(cache[i], cache[i / 3] + 1); // 1을 뺀경우, 3으로 나눈 경우와 비교
			else if (i % 2 == 0) // 2로 나누어 떨어지는 경우
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