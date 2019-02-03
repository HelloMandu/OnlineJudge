#include<iostream>
#include<cmath>
using namespace std;

bool CheckPrimeNumber(int num) {
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int PrimeNumber(int num) {
	int result = 0;
	for (int i = num + 1; i <= num * 2; i++) {
		if (CheckPrimeNumber(i))
			result++;
	}
	return result;
}

int main() {
	int num;
	while (cin >> num) {
		if (num == 0)
			break;
		cout << PrimeNumber(num) << '\n';
	}
	return 0;
}