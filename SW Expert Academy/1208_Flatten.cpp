#include<iostream>
#include<algorithm>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 100
using namespace std;

int box[MAX];
int dump;
void input() {
	cin >> dump;
	for (int j = 0; j < 100; j++) {
		cin >> box[j];
	}
}

int heightDifference() {
	while (dump--) {
		sort(box, box + MAX);
		box[0]++; box[99]--; // 최대값과 최소값에 +1, -1
	}
	sort(box, box + MAX);
	return box[99] - box[0];
}

int main() {
	fastIO();
	for (int i = 1; i <= 10; i++) {
		input();
		cout << '#' << i << ' ' << heightDifference() << '\n';
	}
	return 0;
}