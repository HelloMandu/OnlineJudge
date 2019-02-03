#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	cin >> n;
	int sum = 0, group = 0;
	while (sum < n)
		sum += ++group;
	bool check = group % 2;
	int a = 1;
	for (int i = (sum - group) + 1; i < n; i++) {
		a++; group--;
	}
	if (check)
		cout << group << '/' << a;
	else
		cout << a << '/' << group;
	return 0;
}