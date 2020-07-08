#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<vector>
#define RED false
#define BLUE true
using namespace std;

int n;
int arr[21][21];
int result = INT_MAX;
vector<int> blue, red;


void travalse(int idx) {
	if (blue.size() > n / 2 || red.size() > n / 2) {
		return;
	}
	else if (blue.size() == n / 2 && red.size() == n / 2) {
		int statB = 0, statR = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				int &b1 = blue[i], &b2 = blue[j];
				int &r1 = red[i], &r2 = red[j];
				statB += arr[b1][b2] + arr[b2][b1];
				statR += arr[r1][r2] + arr[r2][r1];
			}
		}
		result = min(result, abs(statB - statR));
		return;
	}
	blue.push_back(idx);
	travalse(idx + 1);
	blue.pop_back();
	red.push_back(idx);
	travalse(idx + 1);
	red.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	travalse(0);
	cout << result;
	return 0;
}
#include<iostream>
#include<climits>
#include<cmath>
#include<algorithm>
#include<vector>
#define RED false
#define BLUE true
using namespace std;

int n;
int arr[21][21];
int result = INT_MAX;
vector<int> blue, red;


void travalse(int idx) {
	if (blue.size() > n / 2 || red.size() > n / 2) {
		return;
	}
	else if (blue.size() == n / 2 && red.size() == n / 2) {
		int statB = 0, statR = 0;
		for (int i = 0; i < n / 2; i++) {
			for (int j = i + 1; j < n / 2; j++) {
				int &b1 = blue[i], &b2 = blue[j];
				int &r1 = red[i], &r2 = red[j];
				statB += arr[b1][b2] + arr[b2][b1];
				statR += arr[r1][r2] + arr[r2][r1];
			}
		}
		result = min(result, abs(statB - statR));
		return;
	}
	blue.push_back(idx);
	travalse(idx + 1);
	blue.pop_back();
	red.push_back(idx);
	travalse(idx + 1);
	red.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	travalse(0);
	cout << result;
	return 0;
}
//#include<iostream>
//#include<algorithm>
//#include<vector>
//#include<cmath>
//using namespace std;
//#pragma warning(disable:4996)
//
//int main() {
//	ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
//	int arr[21][21], n;
//	int result = 2147483647;
//	scanf("%d\n", &n);
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			scanf("%d", &arr[i][j]);
//		}
//	}
//	vector<int> v;
//	for (int i = 0; i < n; i++) {
//		v.push_back(i);
//	}
//	do {
//		int statB = 0, statR = 0;
//		for (int i = 0; i < n / 2; i++) {
//			for (int j = i + 1; j < n / 2; j++) {
//				int& b1 = v[i], & b2 = v[j];
//				int& r1 = v[i + n / 2], & r2 = v[j + n / 2];
//				statB += arr[b1][b2] + arr[b2][b1];
//				statR += arr[r1][r2] + arr[r2][r1];
//			}
//		}
//		result = min(result, abs(statB - statR));
//	} while (next_permutation(v.begin(), v.end()));
//	printf("%d", result);
//	return 0;
//}