#include<iostream>
#include<cstring>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define MAX 1001
using namespace std;

int n, m;
double cache[MAX][2 * MAX];

double percentageClimb(int days = 0, int climb = 0) {
	if (days == m) {
		return climb >= n ? 1 : 0;
	}
	/*메모이제이션*/
	double &ret = cache[days][climb];
	if (ret != -1) {
		return ret;
	}
	/*1칸일 때 *0.25, 2칸일 때 *0.75*/
	return ret = (0.25 * percentageClimb(days + 1, climb + 1)) + (0.75 * percentageClimb(days + 1, climb + 2));
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 2 * m; j++) {
				cache[i][j] = -1;
			}
		}
		printf("%.10lf\n", percentageClimb());
	}
	return 0;
}