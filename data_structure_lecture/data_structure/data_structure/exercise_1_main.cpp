#include "Student.h"
#include "QuickSort.h"
#include <iostream>
using namespace std;

int main()
{
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.0);
	stu[2].InitValue(2005200132, (char*)"������", 3.0);
	QuickSort(stu, 0, 2);
	Print(cout, stu, 3);
	return 0;
}