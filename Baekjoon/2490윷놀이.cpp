#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n = 3;
	int yoot;
	while (n--) {
		int state = 0;
		for (int i = 0; i < 4; i++) {
			cin >> yoot;
			state += yoot;
		}
		switch (state) {
		case 0:
			cout << 'D' << endl;
			break;
		case 1:
			cout << 'C' << endl;
			break;
		case 2:
			cout << 'B' << endl;
			break;
		case 3:
			cout << 'A' << endl;
			break;
		case 4:
			cout << 'E' << endl;
			break;
		}
	}
	return 0;
}