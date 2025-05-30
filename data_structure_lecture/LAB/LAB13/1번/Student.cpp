#include "Student.h"

void Print(ostream& out, Student stu[], int numelement)
{
	for(int i=0; i<numelement; i++)
	{
		stu[i].Print(out);
	}
}
void Student::Print(ostream& out)
{
	out << id << "\t" << name << "\t" << gpa << endl;
}
void Student::InitValue(int _id, char* _name, float _gpa)
{
	id = _id;
	strcpy_s(name, sizeof(name), _name);
	gpa = _gpa;
}
void Student::getValue(int& _id, char* _name, float& _gpa)
{
	_id = id;
	strcpy_s(_name, sizeof(name), name);
	_gpa = gpa;	
}
char* Student::getName()
{
	return name;
}
void Student::operator = (Student stu)
{
	id = stu.id;
	strcpy_s(name, sizeof(name), stu.name);
	gpa = stu.gpa;
}

void PrintByPointer(ostream& out, Student* values[], int numValues)
{
	for(int i=0; i<numValues; i++)
	{
		(*values[i]).Print(out);
	}
}

bool operator> (Student l, Student r)
{
	std::string l_string = l.getName();
	std::string r_string = r.getName();
	if (l_string > r_string)
		return true;
	else
		return false;
}


bool operator<= (Student l, Student r)
{
	std::string l_string = l.getName();
	std::string r_string = r.getName();
	if (l_string <= r_string)
		return true;
	else
		return false;
}

bool operator< (Student l, Student r)
{
	std::string l_string = l.getName();
	std::string r_string = r.getName();
	if (l_string < r_string)
		return true;
	else
		return false;
}
