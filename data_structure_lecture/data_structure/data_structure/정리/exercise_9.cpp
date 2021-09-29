#include "unsorted.h"

int main()
{
    // make test set
    UnsortedType zero_to_four{};
    ItemType elem{};
    for (int i = 0; i < 5; i++)
    {
        elem.Initialize(-1);
        zero_to_four.InsertItem(elem);
    }

    elem.Initialize(-1);
    zero_to_four.DeleteItem(elem);

    return 0;
}