#include<iostream>
#include<vector>
#define fastIO() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define getLsize(root, begin) root - begin // ���� �ڽ��� ������ ����
#define getRsize(root, end) end - root // ������ �ڽ��� ������ ����
using namespace std;

void input(vector<int> &arr, int n) { // �Է¹���
	int key;
	arr.resize(n); // n�����ŭ �Ҵ�
	for (int i = 0; i < n; i++) {
		cin >> key;
		arr[i] = key;
	}
}

int findInorderRoot(vector<int> &pre, vector<int> &ino, int root_index, int begin, int end) { // ���� ��ȸ���� ��Ʈ�� index���� ��ȯ
	for (int i = begin; i <= end; i++) { // ���� ��ȸ�� ��Ʈ�ε����� ã��
		if (ino[i] == pre[root_index])
			return i;
	}
	return root_index;
}

void findPostorder(vector<int> &pre, vector<int> &ino, int preRootIndex, int begin, int end) { // postorder�� ã��
	int inoRootIndex = findInorderRoot(pre, ino, preRootIndex, begin, end); // ���� ��ȸ�� ��Ʈ�ε����� ã��
	if (begin < end) {
		int Lsize = getLsize(inoRootIndex, begin), Rsize = getRsize(inoRootIndex, end); // ���ʻ������ �����ʻ�����
		int Lchild = preRootIndex + 1, Rchild = preRootIndex + Lsize + 1; // �����ڽİ� �������ڽ�
		if (Lsize > 0) // �����ڽ��� ������
			findPostorder(pre, ino, Lchild, begin, inoRootIndex - 1); // L��ġ�� ��Ʈ��
		if (Rsize > 0) // �������ڽ��� ������
			findPostorder(pre, ino, Rchild, inoRootIndex + 1, end); // R��ġ�� ��Ʈ��
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