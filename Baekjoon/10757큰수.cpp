#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

struct BigNum {
	char num[100001];
	int size;

	void init(char num[]) {
		this->size = strlen(num);
		for (int i = 0; i < this->size; i++) {
			this->num[i] = (char)num[this->size - (i + 1)] - '0';
		}
	}
	void print() {
		for (int i = size; i >= 0; i--) {
			cout << (int)num[i];
		}
	}
};

BigNum n1, n2, result;
char num1[100001], num2[100001];

void sum() {
	int carry = 0;
	int length = max(n1.size, n2.size) + 1;
	result.size = length;
	for (int i = 0; i < length; i++) {
		int sum = (carry + n1.num[i] + n2.num[i]);
		result.num[i] = sum % 10;
		if (sum >= 10) { carry = 1; }
		else { carry = 0; }
	}
	for (int i = result.size; i >= 0; i--) {
		if (result.num[i] != 0) {
			break;
		}
		result.size--;
	}
}

int main() {
	cin >> num1 >> num2;
	n1.init(num1), n2.init(num2);
	sum();
	result.print();
	return 0;
}