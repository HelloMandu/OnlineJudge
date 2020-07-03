#include<iostream>
#include<map>
#include<string>
using namespace std;

int parent[200002];
int set[200002];

int getParent(int n) {
	if (parent[n] == n) {
		return n;
	}
	return parent[n] = getParent(parent[n]);
}

int unionParent(int a, int b) {
	int parentA = getParent(a);
	int parentB = getParent(b);
	if (parentA < parentB) {
		parent[parentB] = parentA;
		return set[parentA] += set[parentB];
	}
	else if(parentA > parentB) {
		parent[parentA] = parentB;
		return set[parentB] += set[parentA];
	}
	return set[parentA];
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n, num= 0;
		map<string, int> people;
		string people1, people2;
		cin >> n;
		for (int i = 1; i <= 2 * n; i++) {
			parent[i] = i;
			set[i] = 1;
		}
		while (n--) {
			cin >> people1 >> people2;
			if (people.find(people1) == people.end()) {
				people[people1] = ++num;
			}
			if (people.count(people2) == 0) {
				people[people2] = ++num;
			}
			cout << unionParent(people[people1], people[people2]) << '\n';
		}
		people.clear();
	}
	return 0;
}