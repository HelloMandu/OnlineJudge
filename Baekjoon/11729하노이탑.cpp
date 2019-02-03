#include<iostream>
#include<cmath>
using namespace std;

void HanoiTower(int n, int from = 1, int temp = 2, int to = 3) {
	if (n == 1) {
		cout << from << ' ' << to << '\n';
		return;
	}
	HanoiTower(n - 1, from, to, temp);
	cout << from << ' ' << to << '\n';
	HanoiTower(n - 1, temp, from, to);
}

int main() {
	int n;
	cin >> n; // ¿øÆÇÀÇ °¹¼ö
	cout << (long long)pow(2, n) - 1 << '\n'; // ÃÑ ÀÌµ¿ È½¼ö
	HanoiTower(n);
	return 0;
}