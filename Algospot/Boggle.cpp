/*�޸������̼Ǳ���� �̿��� ����Ž��*/
#include<iostream>
#include<string>
#include<cstring>
#define MAX 7
using namespace std;

char boggle[MAX][MAX] = { 0 };
bool dp[MAX][MAX][10];
string voca;

void setBoggle() { // ������ �Է�
	for (int i = 1; i < MAX - 1; i++)
		for (int j = 1; j < MAX - 1; j++)
			cin >> boggle[i][j];
}

bool findVoca(int i, int j, int present) { // voca�� ã�´�
	if (present == voca.size()) // �ܾ �� ã���� ��
		return true;
	for (int a = i - 1; a <= i + 1; a++) {
		for (int b = j - 1; b <= j + 1; b++) {
			if (a != i || b != j) { // �ڱ� �ε����� �����ϰ� 
				if (boggle[a][b] == voca[present] && !dp[a][b][present]) { // �ܾ ã�Ұ�, �湮���� �ʾ��� ��
					dp[a][b][present] = true; // �湮üũ
					if (findVoca(a, b, present + 1)) // �� ���� �ܾ ã��
						return true;
				}
			}
		}
	}
	return false; // 8���� ����Ǽ��� ��� ���� ��
}

bool checkVoca() { // �ܾ �ִ��� Ȯ��
	int present = 0;
	for (int i = 1; i < MAX - 1; i++) {
		for (int j = 1; j < MAX - 1; j++) {
			if (boggle[i][j] == voca[present]) { // ù��° �ܾ ã���� ��
				if (findVoca(i, j, present + 1)) // �ܾ �ִٸ� true
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
		setBoggle(); // ������ �Է�
		cin >> vocaNum; // �Է¹��� �ܾ��� ��
		while (vocaNum--) {
			cin >> voca; // �ܾ� �Է�
			cout << voca << (checkVoca() ? " YES\n" : " NO\n"); // ������
			memset(dp, false, sizeof(dp));
		}
	}
	return 0;
}