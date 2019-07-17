#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct People {
	int age, order;
	string name;
};

People people[100001];

bool compare(People a, People b) {
	if (a.age == b.age) {
		return a.order < b.order;
	}
	return a.age < b.age;
}

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> people[i].age >> people[i].name;
		people[i].order = i;
	}
	sort(people, people + n, compare);
	for (int i = 0; i < n; i++) {
		cout << people[i].age << ' ' << people[i].name << '\n';
	}
	return 0;
}