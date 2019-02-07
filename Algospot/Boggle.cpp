#include<fstream>
#include<string>
#define MAX 7
using namespace std;

char boggle[MAX][MAX] = { 0 };
string voca;

void SetBoggle(ifstream &inp) { // 게임판 입력
	for (int i = 1; i < MAX - 1; i++)
		for (int j = 1; j < MAX - 1; j++)
			inp >> boggle[i][j];
}

bool FindVoca(int i, int j, int present) { // voca를 찾는다
	if (present == voca.size()) // 단어를 다 찾았을 때
		return true;
	for (int a = i - 1; a <= i + 1; a++) {
		for (int b = j - 1; b <= j + 1; b++) {
			if (a != i || b != j) { // 자기 인덱스를 제외하고 
				if (boggle[a][b] == voca[present]) { // 단어를 찾았을 시
					if (FindVoca(a, b, present + 1)) // 그 다음 단어를 찾음
						return true;
				}
			}
		}
	}
	return false; // 8가지 경우의수가 모두 없을 때
}

bool CheckVoca() { // 단어가 있는지 확인
	int present = 0;
	for (int i = 1; i < MAX - 1; i++) {
		for (int j = 1; j < MAX - 1; j++) {
			if (boggle[i][j] == voca[present]) { // 첫번째 단어를 찾았을 시
				if (FindVoca(i, j, present + 1)) // 단어가 있다면 true
					return true;
			}
		}
	}
	return false;
}

int main() {
	ifstream inp("input.inp");
	ofstream out("output.out");

	int testcase;
	inp >> testcase;
	while (testcase--) {
		int vocaNum;
		SetBoggle(inp); // 게임판 입력
		inp >> vocaNum; // 입력받을 단어의 수
		while (vocaNum--) {
			inp >> voca; // 단어 입력
			out << voca << (CheckVoca() ? " YES\n" : " NO\n"); // 결과출력
		}
	}
	return 0;
}