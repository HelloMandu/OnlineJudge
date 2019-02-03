#include<iostream>
#define MAX 15
using namespace std;

void SetPeople(int people[][MAX]) { // 해당 집의 거주민 수를 초기화
	for (int i = 1; i < MAX; i++)
		people[0][i] = i;
	for (int i = 1; i < MAX; i++)
		for (int j = 1; j < MAX; j++)
			people[i][j] = people[i][j - 1] + people[i - 1][j]; // 해당 집의 거주민 수
}

int main() {
	int testCase, people[MAX][MAX] = { 0 };
	SetPeople(people);
	cin >> testCase;
	while (testCase--) {
		int k, n; // 층, 호
		cin >> k >> n;
		cout << people[k][n] << endl;
	}
	return 0;
}