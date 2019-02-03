#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool Compare(string &a, string &b) {
	if (a.size() == b.size()) {
		for (int i = 0; i < a.size(); i++) {
			if (a[i] != b[i])
				return a[i] < b[i];
		}
	}
	return a.size() < b.size();
}

int main() {
	string voca[20000];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> voca[i];
	sort(voca, voca + n, Compare);
	for (int i = 0; i < n; i++) {
		if (voca[i] != voca[i + 1])
			cout << voca[i] << '\n';
	}
	return 0;
}