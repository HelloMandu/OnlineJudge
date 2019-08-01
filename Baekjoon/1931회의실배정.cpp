#include<iostream>
#include<algorithm>
using namespace std;

struct Conference {
	int start, end;
};
int n;
Conference conference[100001];

bool compare(Conference a, Conference b) {
	if (a.end == b.end) {
		return a.start < b.start;
	}
	return a.end < b.end;
}

int solution() {
	int result = 0;
	int endTime = 0;
	for (int i = 0; i < n; i++) {
		if (endTime <= conference[i].start) {
			endTime = conference[i].end;
			result++;
		}
	}
	return result;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> conference[i].start >> conference[i].end;
	}
	sort(conference, conference + n, compare);
	cout << solution();
	return 0;
}