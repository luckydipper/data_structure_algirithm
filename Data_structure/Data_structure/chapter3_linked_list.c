#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
// linked list(dynamic allocation) vs sequential list(array)
// 자료들이 중복을 허용해서,메모리 공간에서 나란히 이어진 구조.
// ADT : 기능 명세서.
// method(기능)이 먼저임. 그러다보니, 이러한 자료구조가 나옴.
// 기능을 생각하고, 구현해라. method를 상상한 후, structure class를 만들어라.

typedef struct List {
	int current_index;
	int list_size; // end index.
	int buffer[50];
} List;

typedef struct Point {
	int x;
	int y;
} Point;


// List의 type은 뭐야.
// LData의 type은 -> 안에 저장될 data type, template 쓰고 싶네...
// LData를 int만이라도.

// initialize, constructor
void listInit(List* plist);

// insert data to plist's current index
void insert(List* plist, int* data);

// data save, list에, data를
bool beginValue(List* plist, int* data);

// move current index to next index
bool nextValue(List* plist, int* data);

// lremove : 현재 있는 iterator의 값을 삭제한다.
int listRemove(List* plist);

// lcount : 현재 저장되어 있는 수를 반환
int listCount(List* const count);

void printList(List* const plist);

int main()
{
	Point ppos;

	List student_scores;
	listInit(&student_scores);
	
	for (int i = 0; i < 10; i++)
		insert(&student_scores, &i);
	
	printList(&student_scores);
	int ptr_f = 151;
	int* temp_test = &ptr_f;//1563; //PE file에 있는 read only memory라서 바꿀 수 없구나..
	nextValue(&student_scores, temp_test);
	nextValue(&student_scores, temp_test);
	printList(&student_scores);
	listRemove(&student_scores);
	printList(&student_scores);
	return 0;
}

void listInit(List* plist)
{
	*(plist->buffer);
	plist->current_index = 0;
	plist->list_size = 0;
}

void insert(List* plist, int* data) //append를 구현해야함.
{
	//assert(/*buffer over flow*/ plist->buffer < plist->list_size); // test code 따로 빼서 관리.
	//plist->current_index++;
	plist->buffer[plist->list_size] = *data;
	plist->list_size++;
	//plist->buffer[plist->current_index] = &data;
	
}

bool beginValue(List* plist, int* data) //vector의 iterator의 start
{
	plist->current_index = 0;
	*data = plist->buffer[plist->current_index];
	if (plist->current_index > plist->list_size)
		return false;
	else
		return true;
}

bool nextValue(List* plist, int* data)
{
	*data = plist->buffer[plist->current_index];
	printf("current index = %d\n", ++plist->current_index);
	if (plist->current_index > plist->list_size)
		return false;
	else
		return true;
}

// lremove : 현재 있는 iterator의 값을 삭제한다.
int listRemove(List* plist)
{
	int move_index   = plist->current_index;
	int rmoved_value = plist->buffer[move_index];
	int last_index   = plist->list_size - 1;

	for (move_index; move_index < last_index; move_index++)
		plist->buffer[move_index] = plist->buffer[move_index + 1];
	plist->list_size--;
	plist->current_index--;
	return plist->current_index;
}

// lcount : 현재 저장되어 있는 수를 반환
int listCount(List* const plist);


void printList(List* const plist)
{
	int lenth = plist->list_size;
	for (int i = 0; i < lenth; i++)
		printf("%d\n", plist->buffer[i]);
}
