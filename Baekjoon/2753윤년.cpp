#include<iostream>
using namespace std;

int isLeapYear(int year) {
	if (year % 4 == 0) {
		if (year % 100 != 0 || year % 400 == 0) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int year;
	cin >> year;
	cout << isLeapYear(year);
	return 0;
}