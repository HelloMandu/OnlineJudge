#include<iostream>
#include<algorithm>
using namespace std;

struct Line {
	int a, b;
};
Line line[101];
int n;

bool compare(Line x, Line y) {
	return x.a < y.a;
}

int minLine() {
	int cache[101] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (line[i].b > line[j].b) {
				cache[i] = max(cache[i], cache[j]);
			}
		}
		cache[i] += 1;
	}
	int lis = 0;
	for (int i = 0; i < n; i++) {
		lis = max(lis, cache[i]);
	}
	return n - lis;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> line[i].a >> line[i].b;
	}
	sort(line, line + n, compare);
	cout << minLine();
	return 0;
}