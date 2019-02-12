#include<iostream>
#include<vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define getLsize(root, begin) root - begin // 왼쪽 자식의 갯수를 구함
#define getRsize(root, end) end - root // 오른쪽 자식의 갯수를 구함
using namespace std;

void input(vector<int> &arr, int n) { // 입력받음
	int key;
	arr.resize(n); // n사이즈만큼 할당
	for (int i = 0; i < n; i++) {
		cin >> key;
		arr[i] = key;
	}
}

int findInorderRoot(vector<int> &pre, vector<int> &ino, int root_index, int begin, int end) { // 중위 순회에서 루트의 index값을 반환
	for (int i = begin; i <= end; i++) { // 중위 순회의 루트인덱스를 찾음
		if (ino[i] == pre[root_index])
			return i;
	}
	return root_index;
}

void findPostorder(vector<int> &pre, vector<int> &ino, int preRootIndex, int begin, int end) { // postorder을 찾음
	int inoRootIndex = findInorderRoot(pre, ino, preRootIndex, begin, end); // 중위 순회의 루트인덱스를 찾음
	if (begin < end) {
		int Lsize = getLsize(inoRootIndex, begin), Rsize = getRsize(inoRootIndex, end); // 왼쪽사이즈와 오른쪽사이즈
		int Lchild = preRootIndex + 1, Rchild = preRootIndex + Lsize + 1; // 왼쪽자식과 오른쪽자식
		if (Lsize > 0) // 왼쪽자식이 있을시
			findPostorder(pre, ino, Lchild, begin, inoRootIndex - 1); // L위치를 루트로
		if (Rsize > 0) // 오른쪽자식이 있을시
			findPostorder(pre, ino, Rchild, inoRootIndex + 1, end); // R위치를 루트로
	}
	cout << ino[inoRootIndex] << ' ';
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		int n;
		vector<int> pre, ino;
		cin >> n;
		input(pre, n);
		input(ino, n);
		findPostorder(pre, ino, 0, 0, n - 1);
		cout << '\n';
	}
	return 0;
}