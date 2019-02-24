#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

bool areFriends[10][10];
bool taken[10];

int countPairings(int n) {
	/*���� �л����� ���� ��ȣ�� ���� �л��� ã�´�*/
	int firstFree = -1;
	for (int i = 0; i < n; i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}
	/*��� �л��� ¦�� ã���� �� �Ѱ��� ����� ã�����Ƿ� 1�� ��ȯ*/
	if (firstFree == -1) {
		return 1;
	}
	int ret = 0;
	/*firstFree�л��� ¦���� pairWith�л��� ã�� ¦���´�*/
	for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
		if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
			taken[firstFree] = taken[pairWith] = true;
			ret += countPairings(n);
			taken[firstFree] = taken[pairWith] = false;
		}
	}
	return ret;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int p1, p2;
			cin >> p1 >> p2;
			areFriends[p1][p2] = areFriends[p2][p1] = true;
		}
		cout << countPairings(n) << '\n';
		memset(areFriends, false, sizeof(areFriends));
		memset(taken, false, sizeof(taken));
	}
	return 0;
}