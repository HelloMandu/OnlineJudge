#include<iostream>
#include<string>
#include<list>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int main() {
	fastIO();
	string str;
	int n;
	cin >> str;
	list<char> List(str.begin(), str.end());
	list<char>::iterator it = List.end();
	cin >> n;
	while (n--) {
		char alphabet;
		cin >> alphabet;
		switch (alphabet) {
		case 'L':
			if (it != List.begin()) {
				it--;
			}
			break;
		case 'D':
			if (it != List.end()) {
				it++;
			}
			break;
		case 'B':
			if (it != List.begin()) {
				it--;
				it = List.erase(it);
			}
			break;
		case 'P':
			char temp;
			cin >> temp;
			List.insert(it, temp);
			break;
		}
	}
	for (it = List.begin(); it != List.end(); it++) {
		cout << *it;
	}
	List.clear();
	return 0;
}