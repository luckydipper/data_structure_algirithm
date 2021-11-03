#ifndef line_type_11_3
#define line_type_11_3

struct Line
{
	Line* back;
	Line* next;
	static const int line_size = 81;
	char contents[line_size];
	explicit Line(const char* content,const int line_size);
	explicit Line(const Line& line);
	explicit Line();
};

#endif // !line_type_11_3
