#include<iostream>
#include<algorithm>
using namespace std;

int n;
int seq[10001];

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> seq[i];
	}
	if (next_permutation(seq, seq + n)) {
		for (int i = 0; i < n; i++) {
			cout << seq[i] << ' ';
		}
	}
	else {
		cout << "-1";
	}
	return 0;
}