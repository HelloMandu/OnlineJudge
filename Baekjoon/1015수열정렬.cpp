#include<iostream>
using namespace std;

struct Seq {
	int a, p;
	bool operator<=(const Seq &A) {
		if (a == A.a) {
			return p <= A.p;
		}
		return a <= A.a;
	}
};

Seq arr[1001];
int result[1001];

void swap(Seq &a, Seq &b) {
	Seq temp = a;
	a = b;
	b = temp;
}

int partition(Seq arr[], int start, int end) {
	int pivot = start;
	int l = start + 1, r = end;
	while (l <= r) {
		while (arr[l] <= arr[pivot] && l <= r) {
			l++;
		}
		while (arr[pivot] <= arr[r] && start < r) {
			r--;
		}
		if (l <= r) {
			swap(arr[l], arr[r]);
		}
	}
	swap(arr[r], arr[pivot]);
	return r;
}

void qsort(Seq arr[], int start, int end) {
	if (start < end) {
		int pivot = partition(arr, start, end);
		qsort(arr, start, pivot - 1);
		qsort(arr, pivot + 1, end);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].a;
		arr[i].p = i;
	}
	qsort(arr, 0, n - 1);
	for (int i = 0; i < n; i++) {
		result[arr[i].p] = i;
	}
	for (int i = 0; i < n; i++) {
		cout << result[i] << ' ';
	}
	return 0;
}