#include<iostream>
using namespace std;

class Ball {
private:
	int n, m, l; // 사람 수, 공던지는 횟수, n-1보다 작거나 같은 자연수
	int people[1001] = { 0 }; // 각 사람이 공 받은 횟수
	int count = 0; // 공을 총 던진 횟수
public:
	void SetBall() {
		cin >> n >> m >> l;
	}
	int GetResult() {
		int present = 1;
		people[present]++;
		while (people[present] < m) {
			count++; // 공던짐
			if (people[present] % 2) // 홀수 일때
				present = (present + n - l) % n;
			else // 짝수 일때
				present = (present + l) % n;
			people[present]++; // 공받은 횟수++
		}
		return count;
	}
};

int main() {
	Ball ball;
	ball.SetBall();
	cout << ball.GetResult();
	return 0;
}