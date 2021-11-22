#pragma once
#ifndef Sorted_type_10_18
#define Sorted_type_10_18

// Header file for Unsorted List ADT.  
//template <class ItemType_sorted>
//struct NodeType_s;

template<class ItemType_sorted>
struct NodeType_s
{
    ItemType_sorted info;
    NodeType_s* next;
};

// Assumption:  ItemType_sorted is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType_sorted>
class SortedType
{
public:
  SortedType();     // Class constructor	
  ~SortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType_sorted& item, bool& found);
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.
  
  void InsertItem(ItemType_sorted item); 
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list. 
  // Post: item is in list.

  void DeleteItem(ItemType_sorted item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType_sorted&);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  void MergeLists(SortedType<ItemType_sorted>& other, SortedType<ItemType_sorted>& result);
private:
  NodeType_s<ItemType_sorted>* listData;
  int length;
  NodeType_s<ItemType_sorted>* currentPos;
};

template <class ItemType_sorted>
SortedType<ItemType_sorted>::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}
template<class ItemType_sorted>
bool SortedType<ItemType_sorted>::IsFull() const
// Returns true if there is no room for another ItemType_sorted 
//  on the free store; false otherwise.
{
  NodeType_s<ItemType_sorted>* location;
  try
  {
    location = new NodeType_s<ItemType_sorted>;
    delete location;
    return false;
  }
  catch(std::bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType_sorted>
int SortedType<ItemType_sorted>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType_sorted>
void SortedType<ItemType_sorted>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType_s<ItemType_sorted>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType_sorted>
void SortedType<ItemType_sorted>::RetrieveItem(ItemType_sorted& item, 
     bool& found)
{
  bool moreToSearch;
  NodeType_s<ItemType_sorted>* location;

  location = listData;
  found = false;
  moreToSearch = (location != NULL);

  while (moreToSearch && !found)
  {
    if (location->info < item)
    {
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else if (item == location->info)
    {
      found = true;
      item = location->info;
    }
    else
      moreToSearch = false;
  }
}

template <class ItemType_sorted>
void SortedType<ItemType_sorted>::InsertItem(ItemType_sorted item)
{
  NodeType_s<ItemType_sorted>* newNode;  // pointer to node being inserted
  NodeType_s<ItemType_sorted>* predLoc;  // trailing pointer
  NodeType_s<ItemType_sorted>* location; // traveling pointer
  bool moreToSearch;

  location = listData;
  predLoc = NULL;
  moreToSearch = (location != NULL);

  // Find insertion point.
  while (moreToSearch)
  {
    if (location->info < item)
    {
      predLoc = location;
      location = location->next;
      moreToSearch = (location != NULL);
    }
    else
      moreToSearch = false;
  }

  // Prepare node for insertion
  newNode = new NodeType_s<ItemType_sorted>;
  newNode->info = item;
  // Insert node into list.
  if (predLoc == NULL)         // Insert as first
  {
    newNode->next = listData;
    listData = newNode;
  }
  else
  {
    newNode->next = location;
    predLoc->next = newNode;
  }
  length++;
}

template <class ItemType_sorted>
void SortedType<ItemType_sorted>::DeleteItem(ItemType_sorted item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType_s<ItemType_sorted>* iterator = listData->next;
    NodeType_s<ItemType_sorted>* back_iterator = listData;

    while (iterator != NULL)
    {
        if (item == iterator->info)
        {
            back_iterator->next = iterator->next;
            length--;
            delete iterator;
            iterator = back_iterator->next;
            continue;
        }
        back_iterator = iterator;
        iterator = iterator->next;
    }
    if (listData->info == item)
    {
        NodeType_s<ItemType_sorted>* temp_first_node = listData;
        listData = listData->next;
        length--;
        delete temp_first_node;
    }
    //check first item
}
template <class ItemType_sorted>

void SortedType<ItemType_sorted>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType_sorted>
void SortedType<ItemType_sorted>::GetNextItem(ItemType_sorted& item)
// Post:  Current position has been updated; item is 
//        current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;

} 

template <class ItemType_sorted>
SortedType<ItemType_sorted>::~SortedType()
// Post: List is empty; all items have been deallocated.
{
    NodeType_s<ItemType_sorted>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
  }

template <class ItemType_sorted>
void SortedType<ItemType_sorted>::MergeLists(SortedType<ItemType_sorted>& other, SortedType<ItemType_sorted>& result)
{
    result.MakeEmpty();
    other.ResetList();
    this -> ResetList();

    for (int i = 0; i < other.LengthIs(); i++)
    {
        int temp;
        other.GetNextItem(temp);
        result.InsertItem(temp);
    }
    for (int i = 0; i < this->LengthIs(); i++)
    {
        int temp;
        this->GetNextItem(temp);
        result.InsertItem(temp);
    }
}


//궂이 이렇게 구현할 필요가 없을 듯
//NodeType_s<ItemType_sorted>* iterator1 = this->listData;
//NodeType_s<ItemType_sorted>* iterator2 = other.listData;
//
//while (iterator1 != NULL && iterator2 != NULL)
//{
//    if (iterator1->info > iterator2->info)
//    {
//        result.InsertItem(*iterator2);
//        result.InsertItem(*iterator1);
//
//    }
//    iterator1 = iterator1->next;
//    iterator2 = iterator2->next;
//}
#endif // !Sorted_type_10_18
