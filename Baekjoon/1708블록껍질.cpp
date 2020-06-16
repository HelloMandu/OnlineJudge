#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
#pragma warning(disable:4996)

typedef long long lint;

struct Point {
	int y, x;
	int dy, dx; // 기준점과의 거리
};

Point point[100002];

bool comp(const Point &a, const Point &b) {
	if ((lint)a.dy * b.dx != (lint)a.dx * b.dy) {
		return (lint)a.dy * b.dx < (lint)a.dx * b.dy;
	}
	if (a.y != b.y) {
		return a.y < b.y;
	}
	return a.x < b.x;
}
//CW : Clock Wise, CCW : Counter Clock Wise
lint ccw(const Point &a, const Point &b, const Point &c) {
	return (lint)(a.x * b.y + b.x * c.y + c.x * a.y - b.x * a.y - c.x * b.y - a.x * c.y);
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &point[i].x, &point[i].y);
	}
	sort(point, point + n, comp); // y, x좌표가 작은 순으로 정렬
	for (int i = 1; i < n; i++) {
		point[i].dx = point[i].x - point[0].x;
		point[i].dy = point[i].y - point[0].y;
	}
	sort(point + 1, point + n, comp); // 기준에서 반시계방향으로 정렬

	stack<int> Stack;
	// 스택에 first, second를 넣어준다.
	Stack.push(0);
	Stack.push(1);
	int next = 2;
	while (next < n) {
		while (Stack.size() >= 2) {
			int first, second;
			second = Stack.top(); Stack.pop();
			first = Stack.top();
			// first, second, next가 좌회전 ( > 0 )이라면 second push
			// 우회전( < 0 )이라면 위의 while문 계속 반복
			if (ccw(point[first], point[second], point[next]) > 0) {
				Stack.push(second);
				break;
			}
		}
		Stack.push(next++);
	}
	printf("%d", Stack.size());
	return 0;
}