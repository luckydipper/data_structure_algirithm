// 2차원 평면상에 node들을 만들고 이들을 연결한다.
// STL로 자료구조를 가져다 쓰는게 효과적이지 않나?
// 그냥 개념만 알고 구현 할 줄 알면 되는 게 아닌가?

#include <stdio.h>
#include <Windows.h>
#include <assert.h>

// 2D point type
typedef struct Coordinate2D {
    int x_;
    int y_;
}Coordinate2D;

// 
typedef struct node {
    Coordinate2D* p_coordinate;
    struct node* p_next_node;
}Node;

// 
typedef struct LinkedList {
    Node *p_current_node;
    Node *p_header_node;
}LinkedList;

// pointer를 return 하려면, const를 써야지 return 할 수 있지 않나?
// 이곳의 const의 유무가 어떤 역할인지..
// malloc에서 주는 변수는 heep memory에 있으므로, return해도 해제되지 않는군.
// literal도 함수 stack에 저장되지 않으므로, char* name = "blabla" return 해도 되는 군!
// literal과 dynamic allocated pointer는 return해도 됨.
Node* NodeConstructor(const int x, const int y)
{
    Node*         const p_new_node   = (Node*)malloc(sizeof(Node));
    Coordinate2D* const p_2d         = (Coordinate2D*)malloc(sizeof(Coordinate2D));
    
    assert(p_new_node != NULL);
    assert(p_2d       != NULL);

    p_new_node->p_coordinate = p_2d;
    p_new_node->p_coordinate->x_ = x;
    p_new_node->p_coordinate->y_ = y;
    p_new_node->p_next_node = NULL;

    return p_new_node;
}

// 
void ListInit(LinkedList* list)
{
    Node* p_dummy_node = NodeConstructor(/*x = */0, /*y = */ 0);
    list->p_current_node = NULL;
    list->p_header_node = p_dummy_node;
}

// x축 오름차순 
// y축 내림차순


void PrintList(LinkedList* list)
{
    list->p_current_node = list->p_header_node;
    while (list->p_current_node != NULL)
    {
        printf("x coordinate : %d \n", list->p_current_node->p_coordinate->x_);
        printf("y coordinate : %d \n", list->p_current_node->p_coordinate->y_);
        printf("               | \n");
        printf("               V \n");
        list->p_current_node = list->p_current_node->p_next_node;
    };
    printf("             NULL\n\n");
}

// dumy가 깨지는 거 아님? dumpy 다음에 붙히면 되네.
void AppendFront(LinkedList* list, Node* node)
{
    node->p_next_node = list->p_header_node->p_next_node;
    list->p_header_node->p_next_node = node;
}

void Insert();


void DeleteList(LinkedList* list)
{
    list->p_current_node = list->p_header_node;
    while (list->p_current_node != NULL)
    {
        Node* p_delete_node  = list->p_current_node;
        list->p_current_node = list->p_current_node->p_next_node;
        free(p_delete_node->p_coordinate);
        free(p_delete_node);
    };
}


int main()
{
    LinkedList coordinate_list; // 궂이 이렇게 format을 해야 하는지는 의문,
    ListInit(&coordinate_list); // constructor로 생성할 때, format해서 return 해주면 안 됨? Time_T 처럼.
    PrintList(&coordinate_list);
    Node* new_nodes[5];
    Node* p_new_node = NodeConstructor(1, 6);
    AppendFront(&coordinate_list, p_new_node);
    PrintList(&coordinate_list);
    DeleteList(&coordinate_list);
    return 0;
}