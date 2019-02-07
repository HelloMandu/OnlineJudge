#include<fstream>
#include<string>
#define MAX 7
using namespace std;

char boggle[MAX][MAX] = { 0 };
string voca;

void SetBoggle(ifstream &inp) { // ������ �Է�
	for (int i = 1; i < MAX - 1; i++)
		for (int j = 1; j < MAX - 1; j++)
			inp >> boggle[i][j];
}

bool FindVoca(int i, int j, int present) { // voca�� ã�´�
	if (present == voca.size()) // �ܾ �� ã���� ��
		return true;
	for (int a = i - 1; a <= i + 1; a++) {
		for (int b = j - 1; b <= j + 1; b++) {
			if (a != i || b != j) { // �ڱ� �ε����� �����ϰ� 
				if (boggle[a][b] == voca[present]) { // �ܾ ã���� ��
					if (FindVoca(a, b, present + 1)) // �� ���� �ܾ ã��
						return true;
				}
			}
		}
	}
	return false; // 8���� ����Ǽ��� ��� ���� ��
}

bool CheckVoca() { // �ܾ �ִ��� Ȯ��
	int present = 0;
	for (int i = 1; i < MAX - 1; i++) {
		for (int j = 1; j < MAX - 1; j++) {
			if (boggle[i][j] == voca[present]) { // ù��° �ܾ ã���� ��
				if (FindVoca(i, j, present + 1)) // �ܾ �ִٸ� true
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
		SetBoggle(inp); // ������ �Է�
		inp >> vocaNum; // �Է¹��� �ܾ��� ��
		while (vocaNum--) {
			inp >> voca; // �ܾ� �Է�
			out << voca << (CheckVoca() ? " YES\n" : " NO\n"); // ������
		}
	}
	return 0;
}