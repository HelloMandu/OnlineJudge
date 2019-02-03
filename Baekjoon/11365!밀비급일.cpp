#include<iostream>
#include<string>
using namespace std;

int main() {
	string arr;
	while (getline(cin, arr)) {
		if (arr == "END")
			break;
		for (int i = arr.length() - 1; i >= 0; i--)
			cout << arr[i];
		cout << endl;
	}
}