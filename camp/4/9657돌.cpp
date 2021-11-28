#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n;
	int cache[1010];
	cin >> n;
	cache[1] = cache[3] = cache[4] = 1;
	cache[2] = 0;
	for (int i = 5; i <= n; ++i) {
		if (cache[i - 1] && cache[i - 3] && cache[i - 4]) {
			cache[i] = 0;
		}
		else {
			cache[i] = 1;
		}
	}
    cout << (cache[n] == 1 ? "SK" : "CY");
	return 0;
}