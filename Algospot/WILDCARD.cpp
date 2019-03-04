#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int cache[101][101];
string wildCard, str;
vector<string> result;

bool compare(string &a, string &b) {
	int length = (a.size() > b.size()) ? b.size() : a.size();
	for (int i = 0; i < length; i++) {
		if (a[i] > b[i]) {
			return false;
		}
	}
	return a.size() <= b.size();
}

int isWildCard(int w = 0, int s = 0) {
	int &ret = cache[w][s];
	if (ret != -1) {
		return ret;
	}
	while (s < str.size() && w < wildCard.size() && (wildCard[w] == '?' || wildCard[w] == str[s])) {
		w++, s++;
	}
	if (w == wildCard.size()) {
		return ret = (s == str.size());
	}
	if (wildCard[w] == '*') {
		for (int skip = 0; skip + s <= str.size(); skip++) {
			if (isWildCard(w + 1, s + skip)) {
				return ret = 1;
			}
		}
	}
	return ret = 0;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> wildCard;
		int n;
		cin >> n;
		while (n--) {
			memset(cache, -1, sizeof(cache));
			cin >> str;
			if (isWildCard()) {
				result.push_back(str);
			}
		}
		sort(result.begin(), result.end(), compare);
		for (string &str : result) {
			cout << str << '\n';
		}
		result.clear();
	}
	return 0;
}