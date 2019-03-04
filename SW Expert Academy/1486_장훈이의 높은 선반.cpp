#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 21
using namespace std;

int cleck[MAX];
int N, B;
int result = 987654321;

void computeHeight(int present = 0, int allheight = 0) {
	/*기저사례 : 점원 index를 초과 했을 때*/
	if (present > N) {
		return;
	}
	/*기저사례 : 장훈이의 키보다 클 경우*/
	else if (allheight >= B) {
		result = min(result, allheight);
	}
	/*현재 index부터 마지막 index까지의 합*/
	computeHeight(present + 1, cleck[present] + allheight);
	/*현재 index를 제외하고 마지막 index까지의 합*/
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