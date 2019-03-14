#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 10001
using namespace std;

int N, K;
int lecture[MAX];

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> lecture[i];
	}
}

double getMaxSkill() {
	double result = 0;
	for (int i = N - K; i < N; i++) {
		result = (result + lecture[i]) / 2;
	}
	return result;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		input();
		sort(lecture, lecture + N);
		printf("#%d %.6lf\n", t, getMaxSkill());
	}
	return 0;
}