#include<iostream>
using namespace std;

int arr[10001][10001];
int queue[40001];
int front = -1, rear = 0;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void push(int n) {
	queue[rear++] = n;
}

int pop() {
	return queue[++front];
}

int main() {
	int r, c;
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] != 0) {

			}
		}
	}
	return 0;
}