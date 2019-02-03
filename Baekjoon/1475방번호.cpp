#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int NumOfSet(string &N) {
	int plastic[10] = { 0 }, result = 0;
	for (int i = 0; i < N.size(); i++)
		plastic[N[i] - '0']++;
	for (int i = 0; i < 10; i++) {
		if (i != 6 && i != 9) // 6 �Ǵ� 9�� �ƴ� ��
			result = max(result, plastic[i]);
	}
	result = max(result, (plastic[6] + plastic[9] + 1) / 2); // 6, 9�� ���� ��
	return result;
}

int main() {
	string N;
	cin >> N;
	cout << NumOfSet(N);
	return 0;
}