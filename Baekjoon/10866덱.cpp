#include<iostream>
#include<string>
#include<deque>
using namespace std;

/*
push_front X : 정수 X를 덱의 앞에 넣는다.
push_back X : 정수 X를 덱의 뒤에 넣는다.
pop_front : 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
pop_back : 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다.만약, 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
size : 덱에 들어있는 정수의 개수를 출력한다.
empty : 덱이 비어있으면 1을, 아니면 0을 출력한다.
front : 덱의 가장 앞에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
back : 덱의 가장 뒤에 있는 정수를 출력한다.만약 덱에 들어있는 정수가 없는 경우에는 - 1을 출력한다.
*/

int main() {
	int testcase, num;
	string str;
	deque<int> Deque;
	cin >> testcase;
	while (testcase--) {
		cin >> str;
		if (str == "push_front") {
			cin >> num;
			Deque.push_front(num);
		}
		else if (str == "push_back") {
			cin >> num;
			Deque.push_back(num);
		}
		else if (str == "pop_front") {
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.front() << '\n';
				Deque.pop_front();
			}
		}
		else if (str == "pop_back") {
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.back() << '\n';
				Deque.pop_back();
			}

		}
		else if (str == "size") {
			cout << Deque.size() << '\n';
		}
		else if (str == "empty") {
			if (Deque.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front") {
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.front() << '\n';
			}
		}
		else if (str == "back") {
			if (Deque.empty()) {
				cout << "-1\n";
			}
			else {
				cout << Deque.back() << '\n';
			}
		}
	}
	return 0;
}