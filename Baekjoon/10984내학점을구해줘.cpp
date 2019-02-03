#include<iostream>
#include<cmath>
using namespace std;

void GetGradesScore(int subject) {
	int allGrade = 0, grade; // 총 학점, 학점
	double allGPA = 0, gpa; // 총 평점, 평점
	for (int i = 0; i < subject; i++) {
		cin >> grade >> gpa;
		allGrade += grade;
		allGPA += grade * gpa;
	}
	double GPA = round((allGPA / allGrade) * 10) / 10; // 학점
	cout.setf(ios::fixed);
	cout.precision(1);
	cout << allGrade << ' ' << GPA << '\n';
}

int main() {
	int semester; // 학기 수
	cin >> semester;
	while (semester--) {
		int subject; // 과목 수
		cin >> subject;
		GetGradesScore(subject);
	}
	return 0;
}