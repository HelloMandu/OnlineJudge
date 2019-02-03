#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 9
using namespace std;

void FindDwart(vector<int> &dwart, int sum) {
	for (int i = 0; i < MAX - 1; i++) {
		for (int j = i + 1; j < MAX; j++) {
			if (sum - (dwart[i] + dwart[j]) == 100) {
				dwart.erase(dwart.begin() + i);
				dwart.erase(dwart.begin() + j - 1); // i에서 원소하나를 제거했으므로 -1
				return;
			}
		}
	}
}

int main() {
	vector<int> dwart(MAX);
	int sum = 0;
	for (int i = 0; i < MAX; i++) {
		cin >> dwart[i];
		sum += dwart[i];
	}
	FindDwart(dwart, sum);
	sort(dwart.begin(), dwart.end());
	for (int i = 0; i < dwart.size(); i++)
		cout << dwart[i] << '\n';
	return 0;
}