#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

bool Compare(const pair<int, int> &max1, const pair<int, int> &max2) {
	if (max1.second == max2.second)
		return max1.first < max2.first;
	return max1.second > max2.second;
}

void SetArr(int arr[], const int n) {
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
}
void GetReuslt(int arr[], const int n) {
	static vector< pair<int, int> > max;
	double sum = 0;
	int averege, middle, most = 0, maxTemp = 0, range;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (arr[i] == arr[i + 1])
			maxTemp++;
		else {
			max.push_back({ arr[i], maxTemp });
			maxTemp = 0;
		}
	}
	averege = (int)round(sum / n);
	middle = arr[(n - 1) / 2];
	if (max.size() > 1) {
		sort(max.begin(), max.end(), Compare);
		most = (max[1].second == max[0].second) ? max[1].first : max[0].first;
	}
	else
		most = max[0].first;
	range = arr[n - 1] - arr[0];
	cout << averege << '\n' << middle << '\n' << most << '\n' << range << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	int n;
	static int arr[500001];
	cin >> n;
	SetArr(arr, n);
	GetReuslt(arr, n);
	return 0;
}