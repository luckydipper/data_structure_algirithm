#include "QueType.h"
#include "TreeType.h"

int main()
{
	TreeType BinaraySearchTree{};
	BinaraySearchTree.InsertItem('H');
	BinaraySearchTree.InsertItem('Q');
	BinaraySearchTree.InsertItem('D');
	BinaraySearchTree.InsertItem('A');
	BinaraySearchTree.InsertItem('E');
	BinaraySearchTree.InsertItem('P');
	BinaraySearchTree.InsertItem('U');
	BinaraySearchTree.InsertItem('F');
	BinaraySearchTree.InsertItem('T');
	BinaraySearchTree.InsertItem('S');
	bool a = BinaraySearchTree.IsBST();

	return 0;
}