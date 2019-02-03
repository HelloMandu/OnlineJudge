#include<iostream>
#include<string>
#include<queue>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	queue<int> Queue;
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str == "push") {
			int num;
			cin >> num;
			Queue.push(num);
		}
		else if (str == "pop") {
			if (Queue.empty())
				cout << "-1" << endl;
			else {
				cout << Queue.front() << endl;
				Queue.pop();
			}
		}
		else if (str == "size")
			cout << Queue.size() << endl;
		else if (str == "empty") {
			if (Queue.empty())
				cout << "1" << endl;
			else
				cout << "0" << endl;
		}
		else if (str == "front") {
			if (Queue.empty())
				cout << "-1" << endl;
			else
				cout << Queue.front() << endl;
		}
		else if (str == "back") {
			if (Queue.empty())
				cout << "-1" << endl;
			else
				cout << Queue.back() << endl;
		}
	}
	return 0;
}