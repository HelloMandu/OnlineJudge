#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

vector<string> str1(1001), str2(1001);

bool hasSubString(string A, string B) {
	int len = min(A.length(), B.length());
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (A[i] == B[j]) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str1[i];
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str2[i];
	}
	string result = "";
	for (int i = 0; i < n; i++) {
		result += (hasSubString(str1[i], str2[i]) ? "YES\n" : "NO\n");
	}
	cout << result;
	return 0;
}