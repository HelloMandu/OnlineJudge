#include<iostream>
#define TRAIN 4
using namespace std;

int main() {
	int takeOn, takeOff, people = 0, maxPeople = 0;
	for (int i = 0; i < TRAIN; i++) {
		cin >> takeOff >> takeOn;
		people += takeOn - takeOff;
		if (maxPeople < people)
			maxPeople = people;
	}
	cout << maxPeople;
	return 0;
}