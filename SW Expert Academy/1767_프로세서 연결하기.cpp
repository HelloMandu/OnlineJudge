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

int process[MAX][MAX]; // process구성
int result = INF; // 결과 값
int lineLength = 0; // 임시결과 값
int maxCore = 0; // 최대 코어의 수
vector<Core> core; // 코어의 위치

/*process입력*/
void inputProcess(int &n) {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> process[i][j];
			if (process[i][j] == 1 && i != 0 && j != 0 && i != n - 1 && j != n - 1) {
				core.push_back({ i, j }); // 가장자리를 제외한 코어의 위치를 저장
			}
		}
	}
}

/*해당코어가 일정 방향으로 갈 수 있는지 확인*/
bool isLine(int n, int direct, Core &core) {
	switch (direct) {
	case 1: // 상
		for (int i = core.y - 1; i >= 0; i--) {
			if (process[i][core.x] != 0) {
				return false;
			}
		}
		break;
	case 2: // 우
		for (int i = core.x + 1; i < n; i++) {
			if (process[core.y][i] != 0) {
				return false;
			}
		}
		break;
	case 3: // 하
		for (int i = core.y + 1; i < n; i++) {
			if (process[i][core.x] != 0) {
				return false;
			}
		}
		break;
	case 4: // 좌
		for (int i = core.x - 1; i >= 0; i--) {
			if (process[core.y][i] != 0) {
				return false;
			}
		}
		break;
	}
	return true; // 겹치는 코어가 없을 시
}

/*코어에 전선연결*/
void setLine(int n, int direct, Core &core, int dot) {
	switch (direct) {
	case 1: // 상
		for (int i = core.y - 1; i >= 0; i--) {
			process[i][core.x] += dot;
			lineLength += dot;
		}
		return;
	case 2: // 우
		for (int i = core.x + 1; i < n; i++) {
			process[core.y][i] += dot;
			lineLength += dot;
		}
		return;
	case 3: // 하
		for (int i = core.y + 1; i < n; i++) {
			process[i][core.x] += dot;
			lineLength += dot;
		}
		return;
	case 4: // 좌
		for (int i = core.x - 1; i >= 0; i--) {
			process[core.y][i] += dot;
			lineLength += dot;
		}
		return;
	}
}

void traversalProcess(int n, int coreIndex, int connectedCore) { //확인한 코어의 수
	if (coreIndex == core.size()) { // 확인한 코어의 수와 실제 코어의 수가 같을 때
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
		if (isLine(n, direct, core[coreIndex])) { // 전원 연결가능한 지 확인
			setLine(n, direct, core[coreIndex], 1); // 전선 연결
			traversalProcess(n, coreIndex + 1, connectedCore + 1);
			setLine(n, direct, core[coreIndex], -1); // 전선 지움
		}
		else {
			wall++;
		}
	}
	/*4방향 모두 막혀있을 때*/
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