// Header file for class StrType, a specification for the
// String ADT given in Chapter 2.
#include <fstream>
// exercise_29.cpp

#include <iostream>
#include <cstring>
const int MAX_CHARS = 100;

enum RelationType { LESS, EQUAL, GREATER };
enum InType { ALPHA_NUM, ALPHA, NON_WHITE, NOT_NEW };
class StrType
{
public:
	StrType(const char str[]);
	RelationType ComparedTo(StrType& otherString);

private:
	char letters[MAX_CHARS + 1];
};

StrType::StrType(const char str[])
{
	strcpy_s(letters, str);
}

//RelationType StrType::ComparedTo(StrType& otherString)
//{
//	if (strcmp(letters, otherString.letters) == 0)
//		return EQUAL;
//	else if (strcmp(letters, otherString.letters) > 0)
//		return GREATER;
//	else
//		return LESS;
//}


RelationType StrType::ComparedTo(StrType& otherString)
{
	char c1, c2;
	char* str1 = otherString.letters;
	char* str2 = letters;
	while (1) {
		
		c1 = *(str1);
		c2 = *(str2);

		if (c1 != c2)
			return c1 < c2 ? GREATER : LESS;
		if (!c1)
			break;
		str1++;
		str2++;

	}

	return EQUAL;

}


//int main()
//{
//	StrType my_string1{ "hello_worlda" };
//	StrType my_string2{ "hello_worldb" };
//	int result = my_string1.ComparedTo(my_string2);
//
//}

