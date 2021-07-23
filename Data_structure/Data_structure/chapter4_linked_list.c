#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

typedef struct Node {
    int data;
    struct Node* p_next_node;
} Node;


typedef struct LinkedList {
    Node *p_header_node;  // 객체를 가르키는 값
    Node *p_current_node; // 순차적 접근
    Node *p_tail_node;    //
    int list_lenth;
}LinkedList;

// node constructor
Node NodeInit(int data) 
{
    Node node;
    node.data = data;
    return node;
}

// LinkedList constructor
void LinkedListInit(LinkedList* p_linked_lisk)
{
    p_linked_lisk->p_header_node = NULL;
    p_linked_lisk->p_current_node = NULL;
    p_linked_lisk->p_tail_node = NULL;
    int list_lenth = 0; //end null 가르키는 것. 최대 index + 1임.
}


void PushBack(LinkedList* p_linked, int data)
{
    Node *p_new_node = (Node*)malloc(sizeof(Node));
    
    assert(p_new_node != NULL);

    p_new_node->data = data;
    p_new_node->p_next_node = NULL;

    if (p_linked->p_header_node == NULL)
        p_linked->p_header_node = p_new_node;
    else
        p_linked->p_tail_node->p_next_node = p_new_node;

    p_linked->p_tail_node = p_new_node;
    p_linked->list_lenth++;
}


//queue 구조인 듯. list의 뒤로 갈 방법이 존재 해야 하는데
void PopFront(LinkedList* p_linked)
{
    printf("%d is deleted \n", p_linked->p_header_node->data);
    Node* p_delete_node = p_linked->p_header_node;
    p_linked->p_header_node = p_linked->p_header_node->p_next_node;
    free(p_delete_node);
    p_linked->list_lenth--;
}

void DeleteList(LinkedList* p_linked)
{
    p_linked->p_current_node = p_linked->p_header_node;
    while (p_linked->p_current_node != NULL)
    {
        Node *delete_note = p_linked->p_current_node;
        p_linked->p_current_node = p_linked->p_current_node->p_next_node;
        free(delete_note);
    }
    p_linked->list_lenth = 0;
}

void printList(LinkedList* p_linked)
{
    p_linked->p_current_node = p_linked->p_header_node;
    
    assert(p_linked->p_header_node != NULL);

    while (p_linked->p_current_node != NULL)
    {
        printf("%d, \n", p_linked->p_current_node->data);
        p_linked->p_current_node = p_linked->p_current_node->p_next_node;
    }
}

// ui printf("Give me push back value\n");
int main()
{
    LinkedList student_score;
    
    // initialize using constructor
    LinkedListInit(&student_score);
    
    PushBack(&student_score, 16);
    PushBack(&student_score, 14);
    PushBack(&student_score, 19);
    PushBack(&student_score, 165);

    printList(&student_score);
    
    PopFront(&student_score);
    PopFront(&student_score);
    PopFront(&student_score);
    PopFront(&student_score);

    //PushBack(&student_score, 16);
    //PushBack(&student_score, 14);
    //PushBack(&student_score, 19);
    //PushBack(&student_score, 16);
    //PushBack(&student_score, 14);
    //PushBack(&student_score, 19);
    //PushBack(&student_score, 165);
    //PushBack(&student_score, 165);
    //printList(&student_score);
    //DeleteList(&student_score);
    return 0;
}