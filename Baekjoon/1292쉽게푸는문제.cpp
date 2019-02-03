#include<iostream>
using namespace std;

int main() {
	int start, end, result = 0;
	int count = 0;
	cin >> start >> end;
	for (int i = 1; i <= end;) {
		count++;
		for (int j = 1; j <= count; j++) {
			if (start <= i && i <= end)
				result += count;
			i++;
		}
	}
	cout << result;
	return 0;
}