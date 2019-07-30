#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct Stuff {
	int w, v;
};
int n, k;
Stuff stuff[1001];
int cache[1001][1001];
int sumW[1001];
int sumV[1001];

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> stuff[i].w >> stuff[i].v;
	}

	return 0;
}