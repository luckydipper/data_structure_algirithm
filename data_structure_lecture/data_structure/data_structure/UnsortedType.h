// Header file for Unsorted List ADT.  
template <class ItemType>
struct NodeType;
#include <iostream>
using namespace std;
// Assumption:  ItemType is a type for which the operators "<" 
// and "==" are defined?ither an appropriate built-in type or
// a class that overloads these operators.

template <class ItemType>
class UnsortedType
{
public:
  UnsortedType();     // Class constructor	
  ~UnsortedType();    // Class destructor

  bool IsFull() const;
  // Determines whether list is full.
  // Post: Function value = (list is full)

  int  LengthIs() const;
  // Determines the number of elements in list.
  // Post: Function value = number of elements in list.

  void MakeEmpty();
  // Initializes list to empty state.
  // Post:  List is empty.

  void RetrieveItem(ItemType& item, bool& found);
  // Retrieves list element whose key matches item's key 
  // (if present).
  // Pre:  Key member of item is initialized.
  // Post: If there is an element someItem whose key matches 
  //       item's key, then found = true and item is a copy 
  //       of someItem; otherwise found = false and item is 
  //       unchanged. 
  //       List is unchanged.
  
  void InsertItem(ItemType item); 
  // Adds item to list.
  // Pre:  List is not full.
  //       item is not in list. 
  // Post: item is in list.

  void DeleteItem(ItemType item);
  // Deletes the element whose key matches item's key.
  // Pre:  Key member of item is initialized.
  //       One and only one element in list has a key matching
  //       item's key.
  // Post: No element in list has a key matching item's key.

  void ResetList();
  // Initializes current position for an iteration through the
  // list.
  // Post: Current position is prior to list.

  void GetNextItem(ItemType& item);
  // Gets the next element in list.
  // Pre:  Current position is defined.
  //       Element at current position is not last in list.
  // Post: Current position is updated to next position.
  //       item is a copy of element at current position.

  void PrintSumSquares() const;
  void Sort(NodeType<ItemType>* location);

  NodeType<ItemType>* listData;

protected:
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location, NodeType<ItemType>* minPtr);
    NodeType<ItemType>* MinLoc(NodeType<ItemType>* location);

private:
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
UnsortedType<ItemType>::UnsortedType()  // Class constructor
{
  length = 0;
  listData = NULL;
}

template <class ItemType>
UnsortedType<ItemType>::~UnsortedType()
// Class destructor
{
  MakeEmpty();
}  
template<class ItemType>
bool UnsortedType<ItemType>::IsFull() const
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
  catch(bad_alloc exception)
  {
    return true;
  }
}
template <class ItemType>
int UnsortedType<ItemType>::LengthIs() const
// Post: Number of items in the list is returned.
{
  return length;
}
template <class ItemType>
void UnsortedType<ItemType>::MakeEmpty()
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
void UnsortedType<ItemType>::RetrieveItem(ItemType& item, 
    bool& found)
// Pre:  Key member(s) of item is initialized.
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item;
//       otherwise, item is unchanged. 
{
    bool moreToSearch;
    NodeType<ItemType>* location;

    location = listData;
    found = false;
    moreToSearch = (location != NULL);

    while (moreToSearch && !found)
    {
        if (item == location->info)
        {
            found = true;
            item = location->info;
        }
        else
        {
            location = location->next;
            moreToSearch = (location != NULL);
        }
    }
}
template <class ItemType>
void UnsortedType<ItemType>::InsertItem(ItemType item)
// item is in the list; length has been incremented.
{
    NodeType<ItemType>* location;

    location = new NodeType<ItemType>;
    location->info = item;
    location->next = listData;
    listData = location;
    length++;
}
template <class ItemType>
void UnsortedType<ItemType>::DeleteItem(ItemType item)
// Pre:  item's key has been initialized.
//       An element in the list has a key that matches item's.
// Post: No element in the list has a key that matches item's.
{
    NodeType<ItemType>* location = listData;
    NodeType<ItemType>* tempLocation;

    // Locate node to be deleted.
    if (item == listData->info)
    {
        tempLocation = location;
        listData = listData->next;		// Delete first node.
    }
    else
    {
        while (!(item==(location->next)->info))
            location = location->next;

        // Delete node at location->next
        tempLocation = location->next;
        location->next = (location->next)->next;
    }
    delete tempLocation;
    length--;
}

template <class ItemType>
void UnsortedType<ItemType>::ResetList()
// Post: Current position has been initialized.
{
  currentPos = NULL;
}
 
template <class ItemType>
void UnsortedType<ItemType>::GetNextItem(ItemType& item)
// Post:  Current position has been updated; item is current item.
{
  if (currentPos == NULL)
    currentPos = listData;
  else
    currentPos = currentPos->next;
  item = currentPos->info;
} 

// 1.에러 발생 원인 recursive에 잘못된 함수 이름으로 호출함.
// 2.바로 return 0을 썼음. recursive하게 호출 불가능함.
template <typename ItemType>
ItemType SumSquares_a(NodeType<ItemType>* list)
{
    if (list == NULL)
        return 0;
    return (list->info * list->info) + SumSquares_a(list->next);
}

// 에러 발생 원인 
// 1. list 의 값은 직접적으로 옮기면 안됨. 그러면 array를 pointing 할 수 없음.
// 2. 제곱을 더하지 않음
template <typename ItemType>
ItemType SumSquares_b(NodeType<ItemType>* list)
{
    int sum = 0;
    NodeType<ItemType>* iterator = list;
    while (iterator != NULL)
    {
        sum = iterator->info * iterator->info + sum;
        iterator = iterator->next;
    }
    return sum;
}

// 에러 발생 원인
// sumsquares_c 를 호출 해야 함
template <typename ItemType>
ItemType SumSquares_c(NodeType<ItemType>* list)
{
    if (list == NULL)
        return 0;
    return (list->info * list->info) + SumSquares_a(list->next);
}

// 에러 발생 원인
// sumsquares_d를 호출해야함.
template <typename ItemType>
ItemType SumSquares_d(NodeType<ItemType>* list)
{
    if (list->next == NULL)
        return list->info * list->info;
    else
        return list->info * list->info + SumSquares_d(list->next);
}

// 에러 발생 원인
// sumsquare 함수의 return 값의 곱을 reteurn 하려면, sumsquare의 return 값이 list-> info가 돼야 한다.
// 하지만 return 0만 존재했기 때문에 0만 return 되어 0이 출력됐다.
// 이를 해결하기 위해, return 에 sum을 두어 합했다.
template <typename ItemType>
ItemType SumSquares_e(NodeType<ItemType>* list)
{
    if (list == NULL)
    {
        return 0; // 멈추는 조건
    }
    else
    {
        SumSquares_e(list->next);
        static int sum = 0;
        sum += list->info * list->info;
        return sum;
    }    
}

template <class ItemType>
void UnsortedType<ItemType>::PrintSumSquares() const
{
    cout << SumSquares_a(listData) << endl;
    cout << SumSquares_b(listData) << endl;
    cout << SumSquares_c(listData) << endl;
    cout << SumSquares_d(listData) << endl;
    cout << SumSquares_e(listData) << endl;
}


//함수 호출 시 파라미터로 클래스 내부 변수인 listData가 넘겨져야 한다.
template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location,
    NodeType<ItemType>* minPtr)
{
    if (location != NULL) //general case
    {
        if (location->info < minPtr->info)
        {
            minPtr = location;
            return MinLoc(location->next, minPtr); // 다음 노드로 함수 재귀 호출
        }
    }
    else // base case
        return minPtr;
}


template <class ItemType>
NodeType<ItemType>* UnsortedType<ItemType>::MinLoc(NodeType<ItemType>* location) {
    if (location == NULL) // base case: 원래 리스트가 empty (listData가 NULL) 일 때
        return NULL;
    else if (location->next == NULL) // another base case : 리스트의 마지막 노드
        return location;
    else { // general case: location != NULL
        NodeType<ItemType>* minPtr = MinLoc(location->next);
        if (location->info < minPtr->info) // minPtr은 절대 NULL이 아님. Why?
        {
            minPtr = location;
        }
        return minPtr;
    }
}




template <class ItemType>
void UnsortedType<ItemType>::Sort(NodeType<ItemType>* location)
{
    NodeType<ItemType>* minPtr; //최소값을 가리키는 포인터
    ItemType temp;
    if (location != NULL) // empty 리스트가 아니면
    {
        minPtr = MinLoc(location); // ***
        int temp = minPtr->info;
        minPtr->info = location->info;
        location->info = temp;
        Sort(location->next);
        // location에 저장된 값과 minPtr에 저장된 값을 exchange
        // temp에 minPtr->info의 내용을 저장
        //minPtr->info에 location->info를 저장
        //location->info에 temp의 내용 저장
        //다음 노드로(location->next) 재귀함수 호출
    }
    // base case는 do nothing
}
