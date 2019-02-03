#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void StackSequence(int arr[], int testCase) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	vector<char> result;
	stack<int> STACK;
	int index = 0;
	for (int num = 1; num <= testCase; num++) {
		STACK.push(num);
		result.push_back('+');
		while (!STACK.empty() && STACK.top() == arr[index]) {
			STACK.pop();
			result.push_back('-');
			index++;
		}
	}
	if (STACK.empty()) {
		for (int i = 0; i < result.size(); i++)
			cout << result[i] << '\n';
	}
	else
		cout << "NO";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int testCase;
	int arr[100001];
	cin >> testCase;
	for (int i = 0; i < testCase; i++)
		cin >> arr[i];
	StackSequence(arr, testCase);
	return 0;
}