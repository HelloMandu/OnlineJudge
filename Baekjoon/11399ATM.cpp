#include<iostream>
#include<algorithm>
using namespace std;

int people[1001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> people[i];
	sort(people, people + n);
	int result = 0;
	for (int i = 0; i < n; i++)
		result += people[i] * (n - i);
	cout << result;
	return 0;
}