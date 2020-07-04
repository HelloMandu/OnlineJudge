#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int v[101];
int cache[1001][101];
int n, s, m;

int solution(int volume, int depth) {
	if (volume < 0 || volume > m) {
		return -100;
	}
	else if (depth == n) {
		return volume;
	}
	else if (cache[volume][depth] != -1) {
		return cache[volume][depth];
	}
	return cache[volume][depth] = max(solution(volume - v[depth], depth + 1), solution(volume + v[depth], depth + 1));
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	memset(cache, -1, sizeof(cache));
	cin >> n >> s >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	int result = solution(s, 0);
	cout << (result == -100 ? -1 : result);
	return 0;
}