#include "Student.h"
#include <iostream>
#include "BubbleSort.h"
using namespace std;

int main(char argc, char* argv[])
{
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"�̿���", 3.0);
	stu[1].InitValue(2004200121, (char*)"�ǿ���", 3.0);
	stu[2].InitValue(2005200132, (char*)"������", 3.0);
	BubbleSort(stu, 3);
	Print(cout, stu, 3);
	return 0;
}