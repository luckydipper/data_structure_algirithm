#include "HashTable.h"
#include "Student.h"

int main()
{
	Student stu[100];

	stu[0].InitValue(2003200111, (char*)"이웅재", 3.0);
	stu[1].InitValue(2004200121, (char*)"권오준", 3.0);
	stu[2].InitValue(2005200132, (char*)"김진일", 3.0);

	HashTable<Student> ht;

	// stu 배열에 있는 아이템들을 HashTable에 삽입
	for(int i = 0;i < 3;i++)
		ht.InsertItem(stu[i]);

	// 학생 이름 값을 키보드로 입력받는다
	char searching_student_name[100];
	cin >> searching_student_name;
	// HashTable에서 학생 이름을 찾아 출력한다
	Student searching_student;
	searching_student.InitValue(-1, searching_student_name, -1);
	bool found = false;
	ht.RetrieveItem(searching_student, found);


	int id;
	char name[100] = { 0};
	float gpa;
	searching_student.getValue(id, name, gpa);
	cout << "id : " << id << endl << "name : " << name <<endl << "GPA : " << gpa << endl;
	return 0;
}

