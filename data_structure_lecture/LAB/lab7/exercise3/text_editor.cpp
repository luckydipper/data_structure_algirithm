#include "text_editor.hpp"
#include <cstring>
using namespace std;
TextEditor::TextEditor(): current_line(header_padding),number_of_line(0)
{
	header_padding->next = tail_padding;
	tail_padding->back = header_padding;
}

TextEditor::~TextEditor()
{	
	Line* iterator = header_padding;

	while (iterator != tail_padding)
	{
		Line* temp = iterator;
		iterator = iterator->next;
		delete temp;
	}
	delete iterator;
}


void TextEditor::GoToTop()
{
	current_line = header_padding->next;
}

void TextEditor::GoToBottom()
{
	current_line = tail_padding->back;
}

void TextEditor::InsertItem(const char newline[])
{
	Line* added_line = new Line(newline, strlen(newline));
	strcpy_s(added_line->contents, strlen(newline)+1, newline);
	added_line->back = current_line;
	added_line->next = current_line->next;
	current_line->next->back = added_line;
	current_line->next = added_line;
	current_line = added_line;
}