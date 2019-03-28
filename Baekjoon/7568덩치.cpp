#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

struct People {
	int weight, height, rank;
};

People people[201];

int main() {
	fastIO();
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> people[i].weight >> people[i].height;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (people[i].weight < people[j].weight && people[i].height < people[j].height) {
				people[i].rank++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << people[i].rank + 1 << ' ';
	}
	return 0;
}