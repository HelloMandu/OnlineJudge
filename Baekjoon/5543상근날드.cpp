#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int burger[3], cola, cider;
	for (int i = 0; i < 3; i++) {
		cin >> burger[i];
	}
	cin >> cola >> cider;
	int result = 2147483647;
	for (int i = 0; i < 3; i++) {
		result = min(result, burger[i] + cola - 50);
		result = min(result, burger[i] + cider - 50);
	}
	cout << result;
	return 0;
}