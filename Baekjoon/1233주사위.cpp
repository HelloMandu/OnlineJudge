#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int s1, s2, s3;
	int arr[100] = { 0 };
	int Max = 0;
	cin >> s1 >> s2 >> s3;
	for (int i = 1; i <= s1; i++) {
		for (int j = 1; j <= s2; j++) {
			for (int k = 1; k <= s3; k++) {
				arr[i + j + k]++;
			}
		}
	}
	for (int i = 3; i <= s1 + s2 + s3; i++) {
		if (arr[Max] <= arr[i]) {
			if (arr[Max] == arr[i])
				Max = min(Max, i);
			else
				Max = i;
		}
	}
	cout << Max;
	return 0;
}