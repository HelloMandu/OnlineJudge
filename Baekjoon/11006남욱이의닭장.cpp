#include<iostream>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int leg, chicken, u, t;
		cin >> leg >> chicken;
		u = chicken * 2 - leg;
		t = chicken - u;
		cout << u << ' ' << t << '\n';
	}
	return 0;
}