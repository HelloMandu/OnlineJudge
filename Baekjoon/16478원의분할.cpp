#include<iostream>
using namespace std;

int main() {
	int ab, bc, cd;
	double bd;
	cin >> ab >> bc >> cd;
	bd = (double)(ab * cd) / bc;
	printf("%.6lf", bd);
	return 0;
}