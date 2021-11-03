#ifndef test_editor_11_03
#define test_editor_11_03
#include"line.hpp"

class TextEditor
{
private:
    Line* const header_padding = new Line;
    Line* const tail_padding = new Line;
    Line* current_line;
    int number_of_line;

public:
    TextEditor();
    ~TextEditor();
    void GoToTop();
    void GoToBottom();
    void InsertItem(const char newline[]); // end of string -> \n
};



#endif // !test_editor_11_03
