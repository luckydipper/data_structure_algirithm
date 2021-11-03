#include "line.hpp"
#include <cstring>

struct BufferOverflow
{};

Line::Line(const char* content, const int line_size) : back(nullptr), next(nullptr)
{
	if (this->line_size < line_size)
	{
		BufferOverflow error;
		throw error;
	}
	strcpy_s(contents, line_size+1, content);
}

//deep copy..
Line::Line(const Line& line) : back(line.back), next(line.next)
{
	char* const new_content = new char[line_size];
	strcpy_s(new_content, line_size, contents);
}

Line::Line() : back(nullptr), next(nullptr)
{
	*contents = '\n';
}

