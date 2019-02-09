/*메모이제이션기법을 이용한 완전탐색*/
#include<iostream>
#include<string>
#include<cstring>
#define MAX 7
using namespace std;

char boggle[MAX][MAX] = { 0 };
bool dp[MAX][MAX][10];
string voca;

void setBoggle() { // 게임판 입력
	for (int i = 1; i < MAX - 1; i++)
		for (int j = 1; j < MAX - 1; j++)
			cin >> boggle[i][j];
}

bool findVoca(int i, int j, int present) { // voca를 찾는다
	if (present == voca.size()) // 단어를 다 찾았을 때
		return true;
	for (int a = i - 1; a <= i + 1; a++) {
		for (int b = j - 1; b <= j + 1; b++) {
			if (a != i || b != j) { // 자기 인덱스를 제외하고 
				if (boggle[a][b] == voca[present] && !dp[a][b][present]) { // 단어를 찾았고, 방문하지 않았을 시
					dp[a][b][present] = true; // 방문체크
					if (findVoca(a, b, present + 1)) // 그 다음 단어를 찾음
						return true;
				}
			}
		}
	}
	return false; // 8가지 경우의수가 모두 없을 때
}

bool checkVoca() { // 단어가 있는지 확인
	int present = 0;
	for (int i = 1; i < MAX - 1; i++) {
		for (int j = 1; j < MAX - 1; j++) {
			if (boggle[i][j] == voca[present]) { // 첫번째 단어를 찾았을 시
				if (findVoca(i, j, present + 1)) // 단어가 있다면 true
					return true;
			}
		}
	}
	return false;
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int vocaNum;
		setBoggle(); // 게임판 입력
		cin >> vocaNum; // 입력받을 단어의 수
		while (vocaNum--) {
			cin >> voca; // 단어 입력
			cout << voca << (checkVoca() ? " YES\n" : " NO\n"); // 결과출력
			memset(dp, false, sizeof(dp));
		}
	}
	return 0;
}