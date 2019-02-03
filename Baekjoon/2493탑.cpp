#include<iostream>
#include<stack>
using namespace std;

struct Top {
	int index;
	int height;
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n, num;
	stack<Top> Stack;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		while (true) {
			if (Stack.empty()) {
				cout << "0 ";
				Stack.push({ i, num });
				break;
			}
			else if (Stack.top().height > num) {
				cout << Stack.top().index + 1 << ' ';
				Stack.push({ i, num });
				break;
			}
			Stack.pop();
		}
	}

	return 0;
}