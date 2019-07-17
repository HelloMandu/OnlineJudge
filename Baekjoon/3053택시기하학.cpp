#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
using namespace std;

int main() {
	double r;
	cin >> r;
	printf("%.6lf\n%.6lf", M_PI * r * r, 2 * r * r);
	return 0;
}