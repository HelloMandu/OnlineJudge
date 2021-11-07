#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<char> result;
	stack<int> Stack;
	int arr[100001];
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int cur = 0;
	for(int i = 1; i <= n; i++){
		result.push_back('+');
		Stack.push(i);
		while(!Stack.empty() && Stack.top() == arr[cur]){
			result.push_back('-');
			Stack.pop();
			cur++;
		}
	}

	if(Stack.empty()){
		for(int i = 0; i < result.size(); i++){
			cout << result[i] << '\n';
		}
	} else{
		cout << "NO";
	}
	return 0;
}