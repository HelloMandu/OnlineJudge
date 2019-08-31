#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

int n;
stack<int> Stack;

int main() {
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		if (num == 0) {
			Stack.pop();
		}
		else {
			Stack.push(num);
		}
	}
	int sum = 0;
	while (!Stack.empty()) {
		sum += Stack.top();
		Stack.pop();
	}
	cout << sum;
	return 0;
}