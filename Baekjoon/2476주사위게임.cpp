#include<iostream>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int dice[7];
int result = 0;

int getSameEye() {
	int maxindex = 0;
	for (int i = 1; i < 7; i++) {
		if (dice[maxindex] <= dice[i]) {
			maxindex = i;
		}
	}
	return maxindex;
}

int getMoney(int maxindex) {
	switch (dice[maxindex]) {
	case 3:
		return 10000 + maxindex * 1000;
	case 2:
		return 1000 + maxindex * 100;
	case 1:
		return maxindex * 100;
	}
}
int main() {
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			int eye;
			cin >> eye;
			dice[eye]++;
		}
		int maxindex = getSameEye();
		result = max(result, getMoney(maxindex));
		memset(dice, 0, sizeof(dice));
	}
	cout << result;
	return 0;
}