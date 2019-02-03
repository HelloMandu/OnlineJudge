#include<iostream>
#include<string>
#include<deque>
using namespace std;

/*
push_front X : ���� X�� ���� �տ� �ִ´�.
push_back X : ���� X�� ���� �ڿ� �ִ´�.
pop_front : ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
pop_back : ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�.����, ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
size : ���� ����ִ� ������ ������ ����Ѵ�.
empty : ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
front : ���� ���� �տ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
back : ���� ���� �ڿ� �ִ� ������ ����Ѵ�.���� ���� ����ִ� ������ ���� ��쿡�� - 1�� ����Ѵ�.
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