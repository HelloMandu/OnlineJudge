#include<iostream>
#include<queue>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int K, N;

/*���� ������*/
class RNG {
private:
	/*unsigned�̹Ƿ� 2^32�� ���� �ʿ� ����*/
	unsigned seed;
public:
	/*�ʱ������ seed�� 1983���� �ʱ�ȭ*/
	RNG() :seed(1983) {}
	/*��ȣ�� ����, ��ȯ*/
	unsigned int next() {
		unsigned int ret = seed;
		seed = seed * 214013u + 2531011u;
		return ret % 10000 + 1;
	}
};

int getCount() {
	RNG *rng = new RNG();
	queue<int> Queue;
	int count = 0, sum = 0;
	for (int i = 0; i < N; i++) {
		int signal = rng->next();
		sum += signal;
		Queue.push(signal);
		/*K���� Ŭ ��*/
		while (sum > K) {
			sum -= Queue.front();
			Queue.pop();
		}
		/*K���� ���� ��*/
		if (sum == K) {
			count++;
		}
	}
	delete rng;
	return count;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		cin >> K >> N;
		cout << getCount() << '\n';
	}
	return 0;
}