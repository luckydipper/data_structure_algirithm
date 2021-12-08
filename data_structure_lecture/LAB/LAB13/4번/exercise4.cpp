#include "Student.h"
#include <iostream>
#include "HeapSort.h"

using namespace std;

int main(char argc, char* argv[])
{
	Student stu[100];
	stu[0].InitValue(2003200111, (char*)"ÀÌ¿õÀç", 3.0);
	stu[1].InitValue(2004200121, (char*)"±Ç¿ÀÁØ", 3.0);
	stu[2].InitValue(2005200132, (char*)"±èÁøÀÏ", 3.0);

	HeapSort(stu, 3);
	Print(cout, stu, 3);
	return 0;
}