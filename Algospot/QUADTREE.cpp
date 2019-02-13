#include<iostream>
#include<string>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
using namespace std;

string getReverseQuadtree(string::iterator &it) {
	char ch = *(it++);
	if (ch == 'b' || ch == 'w') { // b 또는 w일때 반환
		return string(1, ch);
	}
	string upperLeft = getReverseQuadtree(it);
	string upperRight = getReverseQuadtree(it);
	string lowerLeft = getReverseQuadtree(it);
	string lowerRight = getReverseQuadtree(it);
	/*upperLeft <-> lowerLeft, upperRight <-> lowerRight
	재귀호출결과를 바꾸어 문자열 재분배*/
	return "x" + lowerLeft + lowerRight + upperLeft + upperRight;
}

int main() {
	fastIO();
	int testcase;
	cin >> testcase;
	while (testcase--) {
		string quadtree;
		cin >> quadtree;
		string::iterator it = quadtree.begin();
		cout << getReverseQuadtree(it) << '\n';
	}
	return 0;
}