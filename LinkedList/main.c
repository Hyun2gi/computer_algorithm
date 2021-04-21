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
    node->data = item;
    node->link = L->head;
    L->head = node;
}


void add(LinkedListType* L, int pos, int item)
{
    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    ListNode* before = L->head;
    for(int i=0; i < pos-1; i++)
        before = before->link;
    node->data = item;
    node->link = before->link;
    before->link = node;
}

int get(LinkedListType* L, int pos)
{
    ListNode* p = L->head;
    for(int i=1; i< pos; i++)
        p = p->link;
    return p->data;
}

void set(LinkedListType* L, int pos, int item)
{
    ListNode* p = L->head;
    for(int i=1; i< pos; i++)
        p = p->link;
    p->data = item;
}


void printList(LinkedListType* L)
{
    for(ListNode* p = L->head; p != NULL; p = p->link)
        printf("[%d] -> ", p->data);
    printf("NULL\n");
}

int main()
{
    LinkedListType list;
    init(&list);

    addFirst(&list, 10); printList(&list);
    addFirst(&list, 20); printList(&list);
    addFirst(&list, 30); printList(&list);
    getchar();
    add(&list,1, 40); printList(&list);
    add(&list,1, 50); printList(&list);
    add(&list,3, 60); printList(&list);
    int pos;
    printf("\n �� �� ����� ���� ��ȯ�ұ��?");
    scanf("%d", &pos);
    printf("%d�� ����� ���� %d\n", pos,get(&list, pos));
}
