#include<iostream>
#include<cmath>
using namespace std;

void GetGradesScore(int subject) {
	int allGrade = 0, grade; // �� ����, ����
	double allGPA = 0, gpa; // �� ����, ����
	for (int i = 0; i < subject; i++) {
		cin >> grade >> gpa;
		allGrade += grade;
		allGPA += grade * gpa;
	}
	double GPA = round((allGPA / allGrade) * 10) / 10; // ����
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << allGrade << ' ' << GPA << '\n';
}

int main() {
	int semester; // �б� ��
	cin >> semester;
	while (semester--) {
		int subject; // ���� ��
		cin >> subject;
		GetGradesScore(subject);
	}
	return 0;
}