// Header file for Unsorted List ADT.  
#ifndef sorted_lab7_11_3
#define sorted_lab7_11_3
using namespace std;
#include <cstddef>
#include <iostream>
#include <new>

template <class ItemType>
struct NodeType;
// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined-either an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class SortedType
{
public:
  SortedType();	
  ~SortedType();

  bool IsFull() const;

  int  LengthIs() const;

  void MakeEmpty();

  void RetrieveItem(ItemType& item, bool& found);
  
  void InsertItem(ItemType item); 

  void DeleteItem(ItemType item);

  void ResetList();

  void GetNextItem(ItemType&);

  void PrintReverse() const;

private:
  NodeType<ItemType>* listData;
  int length;
  NodeType<ItemType>* currentPos;
};
template<class ItemType>
struct NodeType
{
    ItemType info;
    NodeType* next;
};
template <class ItemType>
SortedType<ItemType>::SortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}
template<class ItemType>
bool SortedType<ItemType>::IsFull() const
// Returns true if there is no room for another ItemType 
//  on the free store; false otherwise.
{
  NodeType<ItemType>* location;
  try
  {
    location = new NodeType<ItemType>;
    delete location;
    return false;
  }
  catch(bad_alloc &exception)
  {
    return true;
  }
}
template <class ItemType>
int SortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void SortedType<ItemType>::MakeEmpty()
// Post: List is empty; all items have been deallocated.
{
    NodeType<ItemType>* tempPtr;

    while (listData != NULL)
    {
        tempPtr = listData;
        listData = listData->next;
        delete tempPtr;
    }
    length = 0;
}
template <class ItemType>
void SortedType<ItemType>::RetrieveItem(ItemType& item, 
     bool& found)
{
  bool moreToSearch;
  NodeType<ItemType>* location;

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

//template <class ItemType>
//void SortedType<ItemType>::InsertItem(ItemType item)
//{
//  NodeType<ItemType>* newNode;  // pointer to node being inserted
//  NodeType<ItemType>* predLoc;  // trailing pointer
//  NodeType<ItemType>* location; // traveling pointer
//  bool moreToSearch;
//
//  location = listData;
//  predLoc = NULL;
//  moreToSearch = (location != NULL);
//
//  // Find insertion point.
//  while (moreToSearch)
//  {
//    if (location->info < item)
//    {
//      predLoc = location;
//      location = location->next;
//      moreToSearch = (location != NULL);
//    }
//    else
//      moreToSearch = false;
//  }
//
//  // Prepare node for insertion
//  newNode = new NodeType<ItemType>;
//  newNode->info = item;
//  // Insert node into list.
//  if (predLoc == NULL)         // Insert as first
//  {
//    newNode->next = listData;
//    listData = newNode;
//  }
//  else
//  {
//    newNode->next = location;
//    predLoc->next = newNode;
//  }
//  length++;
//}

//template <class ItemType>
//void SortedType<ItemType>::DeleteItem(ItemType item)
//// Pre:  item's key has been initialized.
////       An element in the list has a key that matches item's.
//// Post: No element in the list has a key that matches item's.
//{
//    NodeType<ItemType>* location = listData;
//    NodeType<ItemType>* tempLocation;
//
//    // Locate node to be deleted.
//    if (item == listData->info)
//    {
//        tempLocation = location;
//        listData = listData->next;		// Delete first node.
//    }
//    else
//    {
//        while (!(item==(location->next)->info))
//          location = location->next;
//
//        // Delete node at location->next
//        tempLocation = location->next;
//        location->next = (location->next)->next;
//    }
//    delete tempLocation;
//    length--;
//}

template <class ItemType>
void SortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void SortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is 
//        current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  item = currentPos->info; 
  currentPos = currentPos->next;

} 

// for로 고치는게 깔끔할 듯.
template <class ItemType>
SortedType<ItemType>::~SortedType()
// Post: List is empty; a
{
    if (listData == NULL)
        return;
    
    NodeType<ItemType>* iterator;
    NodeType<ItemType>* pred;
    iterator = listData->next;

    while (iterator != listData)
    {
        pred = iterator;
        iterator = iterator->next;
        delete pred;
    }
    //
    delete iterator;
  }


/*----circle.cpp--------*/

template<class ItemType>
void FindItem(NodeType<ItemType>* listData,
    ItemType item,
    NodeType<ItemType>*& location,
    NodeType<ItemType>*& predLoc,
    bool& found)
    // Assumption: ItemType is a type for which the operators ''<'' and
    //      "==" are defined as either an appropriate built-in type or a
    //      class that overloads these operations.
    // Pre: List is not empty.
    // Post:If there is an element someItem whose key matches item's
    //      key, then found = true; otherwise, found = false.
    //      If found, location contains the address of someItem and
    //      predLoc contains the address of someItem's predecessor;
    //      otherwise, location contains the address of item's logical
    //      successor and predLoc contains the address of item's
    //      logical predecessor.
{
    bool moreToSearch = true;

    location = listData->next;
    predLoc = listData;
    found = false;

    while (moreToSearch && !found)
    {
        if (item < location->info)
            moreToSearch = false;
        else if (item == location->info)
            found = true;
        else
        {
            predLoc = location;
            location = location->next;
            moreToSearch = (location != listData->next);
        }
    }
}

template<class ItemType>
void SortedType<ItemType>::InsertItem(ItemType item)
{
    NodeType<ItemType>* newNode;
    NodeType<ItemType>* predLoc;
    NodeType<ItemType>* location;
    bool found;

    newNode = new NodeType<ItemType>;
    newNode->info = item;
    if (listData != NULL)
    {
        FindItem(listData, item, location, predLoc, found);
        newNode->next = predLoc->next;
        predLoc->next = newNode;
        // If this is last node in list, reassign listData.
        if (listData->info < item)
            listData = newNode;
    }
    else // Inserting into an empty list.
    {
        listData = newNode;
        newNode->next = newNode; //-----------------------------이 코드가 왜 들어갔는지 모르겠음. dumy node임?아니 왜 굳이? circular list로?
    }
    length++;
}

template<class ItemType>
void SortedType<ItemType>::DeleteItem(ItemType item)
{
    NodeType<ItemType>* location;
    NodeType<ItemType>* predLoc;
    bool found;

    FindItem(listData, item, location, predLoc, found);
    if (predLoc == location) // Only node in list?
        listData = NULL;
    else
    {
        predLoc->next = location->next;
        if (location == listData) // Deleting last node in list?
            listData = predLoc;
    }
    delete location;
    length--;
}

// This function should be called by circular list
template<class ItemType>
NodeType<ItemType>* GetBackNode(const NodeType<ItemType>* const front_node)
{
    NodeType<ItemType>* iterator = const_cast<NodeType<ItemType>*> (front_node);
    while (iterator->next != front_node)
        iterator = iterator->next;
    return iterator;
}

// 이럴바엔 doubly linked list로 구현하는게 좋을 듯?
// stack에 저장했다가 한번에 빼는게 시간복잡도상 이득일까? 
// kernel에 요청 해야 하는데? 아니면 그냥 이동하는 것이 이득일까?
// 짧으면 이동하는게 유리할 것 같고, 길면 kernel에 요청하는게 빠르겠다.
template<class ItemType>
void SortedType<ItemType>::PrintReverse() const
{
    cout << listData->info << endl;
    NodeType<ItemType>* back_iterator = listData;
    while (GetBackNode(back_iterator) != listData)
    {
        back_iterator = GetBackNode(back_iterator);
        cout << back_iterator->info << endl;
    }
    return;
}



#endif // !sorted_lab7_11_3