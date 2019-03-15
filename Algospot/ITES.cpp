#include<iostream>
#include<queue>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

int K, N;

/*난수 생성기*/
class RNG {
private:
	/*unsigned이므로 2^32로 나눌 필요 없음*/
	unsigned seed;
public:
	/*초기생성시 seed를 1983으로 초기화*/
	RNG() :seed(1983) {}
	/*신호를 갱신, 반환*/
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
		/*K보다 클 떄*/
		while (sum > K) {
			sum -= Queue.front();
			Queue.pop();
		}
		/*K보다 작을 때*/
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