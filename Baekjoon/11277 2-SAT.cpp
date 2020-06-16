#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

typedef vector<int> vi;
const int n_ = 20 * 2 + 2;
int n, m, cnt, scc[n_], chk[n_], ans[n_];
vi gph[n_];
vector<vi> res;
stack<int> stk;
int getSCC(int now) {
	chk[now] = ++cnt;
	int ret = chk[now];
	stk.push(now);
	for (int nxt : gph[now]) {
		if (!chk[nxt]) ret = min(ret, getSCC(nxt));
		else if (!scc[nxt]) ret = min(ret, chk[nxt]);
	}
	if (ret != chk[now]) return ret;
	res.push_back(vi());
	while (1) {
		int top = stk.top();
		stk.pop();
		scc[top] = res.size();
		res[res.size() - 1].push_back(top);
		ans[top] = res.size();
		if (top == now) break;
	}
	return ret;
}

int f(int u) {
	return u > n ? u - n : u + n;
}

int main() {
	cin >> n >> m;
	while (m--) {
		int u, v;
		cin >> u >> v;
		if (u < 0) u = -u + n;
		if (v < 0) v = -v + n;
		gph[f(u)].push_back(v);
		gph[f(v)].push_back(u);
	}

	for (int i = 1; i <= 2 * n; i++) {
		if (!chk[i]) getSCC(i);
	}

	for (int i = 1; i <= n; i++) {
		if (ans[i] == ans[i + n]) return !puts("0");
	}
	puts("1");

	return 0;
}