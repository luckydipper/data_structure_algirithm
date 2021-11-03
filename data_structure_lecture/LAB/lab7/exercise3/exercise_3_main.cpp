#include "line.hpp"
#include "text_editor.hpp"
#include <iostream>

int main()
{
	TextEditor file;
	file.InsertItem("Heesung Kim\n");
	file.InsertItem("Heesong Kim\n");
	file.InsertItem("Hee Kim\n");
	return 0;
}