#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100001
using namespace std;

int N, M, maxTime;
int examTime[MAX];

void input() {
	maxTime = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> examTime[i];
		maxTime = max(maxTime, examTime[i]);
	}
}

long long shortestTime() {
	long long start = 1, end = 1e14 + 1; // 최소시간, 최대시간
	long long mid, result = 1e14 + 1;
	while (start <= end) {
		long long sumPeople = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < N; i++) {
			sumPeople += mid / examTime[i]; // mid초 안에 수용가능한 인원
		}
		if (sumPeople >= M) { // mid초 안에 모든인원 수용 가능할 때
			result = min(result, mid);
			end = mid - 1;
		}
		else { // mid초 안에 모든인원 수용 불가능할 때
			start = mid + 1;
		}
	}
	return result;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		input();
		cout << '#' << t << ' ' << shortestTime() << '\n';
	}
	return 0;
}