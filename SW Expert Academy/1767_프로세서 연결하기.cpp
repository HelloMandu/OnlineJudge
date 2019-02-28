#include<iostream>
#include<vector>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MAX 12
#define INF 987654321
using namespace std;

struct Core {
	int y;
	int x;
};

int process[MAX][MAX]; // process����
int result = INF; // ��� ��
int lineLength = 0; // �ӽð�� ��
int maxCore = 0; // �ִ� �ھ��� ��
vector<Core> core; // �ھ��� ��ġ

/*process�Է�*/
void inputProcess(int &n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> process[i][j];
			if (process[i][j] == 1 && i != 0 && j != 0 && i != n - 1 && j != n - 1) {
				core.push_back({ i, j }); // �����ڸ��� ������ �ھ��� ��ġ�� ����
			}
		}
	}
}

/*�ش��ھ ���� �������� �� �� �ִ��� Ȯ��*/
bool isLine(int n, int direct, Core &core) {
	switch (direct) {
	case 1: // ��
		for (int i = core.y - 1; i >= 0; i--) {
			if (process[i][core.x] != 0) {
				return false;
			}
		}
		break;
	case 2: // ��
		for (int i = core.x + 1; i < n; i++) {
			if (process[core.y][i] != 0) {
				return false;
			}
		}
		break;
	case 3: // ��
		for (int i = core.y + 1; i < n; i++) {
			if (process[i][core.x] != 0) {
				return false;
			}
		}
		break;
	case 4: // ��
		for (int i = core.x - 1; i >= 0; i--) {
			if (process[core.y][i] != 0) {
				return false;
			}
		}
		break;
	}
	return true; // ��ġ�� �ھ ���� ��
}

/*�ھ ��������*/
void setLine(int n, int direct, Core &core, int dot) {
	switch (direct) {
	case 1: // ��
		for (int i = core.y - 1; i >= 0; i--) {
			process[i][core.x] += dot;
			lineLength += dot;
		}
		return;
	case 2: // ��
		for (int i = core.x + 1; i < n; i++) {
			process[core.y][i] += dot;
			lineLength += dot;
		}
		return;
	case 3: // ��
		for (int i = core.y + 1; i < n; i++) {
			process[i][core.x] += dot;
			lineLength += dot;
		}
		return;
	case 4: // ��
		for (int i = core.x - 1; i >= 0; i--) {
			process[core.y][i] += dot;
			lineLength += dot;
		}
		return;
	}
}

void traversalProcess(int n, int coreIndex, int connectedCore) { //Ȯ���� �ھ��� ��
	if (coreIndex == core.size()) { // Ȯ���� �ھ��� ���� ���� �ھ��� ���� ���� ��
		if (connectedCore > maxCore) {
			result = lineLength;
			maxCore = connectedCore;
		}
		else if (connectedCore == maxCore) {
			result = min(result, lineLength);
		}
		return;
	}
	int wall = 0;
	for (int direct = 1; direct <= 4; direct++) {
		if (isLine(n, direct, core[coreIndex])) { // ���� ���ᰡ���� �� Ȯ��
			setLine(n, direct, core[coreIndex], 1); // ���� ����
			traversalProcess(n, coreIndex + 1, connectedCore + 1);
			setLine(n, direct, core[coreIndex], -1); // ���� ����
		}
		else {
			wall++;
		}
	}
	/*4���� ��� �������� ��*/
	if (wall == 4) {
		traversalProcess(n, coreIndex + 1, connectedCore);
	}
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++) {
		int n;
		inputProcess(n);
		traversalProcess(n, 0, 0);
		cout << '#' << t << ' ' << result << '\n';
		result = INF;
		maxCore = 0;
		core.clear();
	}
	return 0;
}