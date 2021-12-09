#include "HashTable.h"
#include "Student.h"

int main()
{
	Student stu[100];

	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.0);
	stu[2].InitValue(2005200132, (char*)"������", 3.0);

	HashTable<Student> ht;

	// stu �迭�� �ִ� �����۵��� HashTable�� ����
	for(int i = 0;i < 3;i++)
		ht.InsertItem(stu[i]);

	// �л� �̸� ���� Ű����� �Է¹޴´�
	char searching_student_name[100];
	cin >> searching_student_name;
	// HashTable���� �л� �̸��� ã�� ����Ѵ�
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

