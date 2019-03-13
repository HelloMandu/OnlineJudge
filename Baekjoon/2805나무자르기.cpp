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
			if (trees[i] - mid > 0) { // 자를 수 있을 때
				allHeight += trees[i] - mid; // 자른 높이를 더해줌
			}
		}

		if (allHeight >= M) { // 총 자른 높이가 최소높이를 넘어설 때
			start = mid + 1;
			result = max(result, mid); // 자를 수 있는 높이의 최댓값을 저장
		}
		else { // 총 자른 높이가 최소높이 이하일 때
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