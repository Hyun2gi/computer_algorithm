#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode
{
    int data;
    struct ListNode* link;
}ListNode;

typedef struct
{
    ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL;
}

void addFirst(LinkedListType* L, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node -> data = item;
    node -> link = L->head;
    L->head = node;
}

void addLast(LinkedListType* L, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    node -> data = item;
    for(int i=0;before->link != NULL;i++)
        before = before->link;
    before->link = node;
    node-> link = NULL;
}

void add(LinkedListType* L,int pos, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i = 0; i<pos-1; i++)
        before = before->link;
    node -> data = item;
    node -> link = before->link;
    before->link = node;
}


void printList(LinkedListType* L)
{
    for(ListNode* p = L->head; p != NULL; p = p->link)
        printf("[%d] -> ", p->data);
    printf("NULL\n");
}

int get(LinkedListType* L, int pos)
{
    ListNode* p = L->head;
    for(int i=1;i<pos;i++)
        p = p->link;
    return p->data;
}

void set(LinkedListType* L, int pos, int item)
{
    ListNode* p = L->head;
    for(int i=1;i<pos;i++)
        p = p->link;
    p->data = item;
}

void remove1(LinkedListType* L, int pos)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i = 0; i<pos-1; i++)
        before = before->link;
    node = before->link;
    before->link = node->link;
    node -> link = NULL;
    node -> data = NULL;
}

void removeFirst(LinkedListType* L)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node = L->head;
    L->head = node->link;
    node -> link = NULL;
    node -> data = NULL;
}

void removeLast(LinkedListType* L)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i=0;(before->link)->link != NULL;i++)
        before = before->link;
    node = before->link;
    node -> data = NULL;
    before->link = NULL;
}


int main()
{
    LinkedListType list;
    init(&list);

    addFirst(&list, 10) ; printList(&list);
    addFirst(&list, 20) ; printList(&list);
    addFirst(&list, 30) ; printList(&list);
    getchar();
    add(&list,1,40); printList(&list);
    add(&list,1,50); printList(&list);
    add(&list,3,60); printList(&list);
    getchar();
    addLast(&list,70); printList(&list);
    addLast(&list,80); printList(&list);
    addLast(&list,90); printList(&list);
    int pos;
    printf("\n 몇 번 노드의 값을 반환할까요?");
    scanf("%d", &pos);
    printf("%d번 노드의 값은 %d\n", pos, get(&list,pos));
    getchar();
    remove1(&list,1); printList(&list);
    remove1(&list,1); printList(&list);
    remove1(&list,5); printList(&list);
    getchar();
    removeFirst(&list); printList(&list);
    removeFirst(&list); printList(&list);
    removeFirst(&list); printList(&list);
    getchar();
    removeLast(&list); printList(&list);
    removeLast(&list); printList(&list);
}
