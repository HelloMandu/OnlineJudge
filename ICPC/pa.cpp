#include<iostream>
#include<queue>
using namespace std;
#pragma warning(disable:4996)

typedef long long lint;
queue<lint> a;
queue<lint> b;
lint atime = 0, btime = 0;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		lint n1, n2;
		scanf("%lld %lld", &n1, &n2);
		a.push(n1); b.push(n2);
	}
	while (!a.empty() && !b.empty()) {
		if (a.front() + atime < b.front() + btime) {
			atime += a.front();
			a.pop(); b.pop();
		}
		else if (a.front() + atime > b.front() + btime) {
			btime += b.front();
			a.pop(); b.pop();
		}
		else {
			a.push(a.front()); b.push(b.front());
			a.pop(); b.pop();
		}
	}
	printf("%lld", (atime > btime ? atime : btime));
	return 0;
}
