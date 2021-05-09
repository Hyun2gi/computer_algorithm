#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t) = (x),(x) = (y), (y) = (t))

typedef struct DListNode
{
    int elem;
    struct DListNode* prev, * next;
}DListNode;


typedef struct
{
    DListNode* H;
    DListNode* T;
}SetType;


void initNode(DListNode* H, DListNode* T)
{
    H->next = T;
    T->prev = H;
}


void addLast(SetType* L, int item)
{
    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    DListNode* before = L->H;
    node->elem = item;
    for(int i=0;before->next != NULL;i++)
        before = before->next;
    before->next = node;
    node->prev = before;
    node->next = NULL;
}


void printList(SetType* L)
{
    for(DListNode* p = L->H; p != NULL; p = p->next)
        printf("[%d] -> ", p->elem);
    printf("NULL\n");
}

void insertion_sort(SetType* list)
{

    DListNode* node = (DListNode*)malloc(sizeof(DListNode));
    DListNode* prev = (DListNode*)malloc(sizeof(DListNode));
    DListNode* before = list->H;
    before=before->next;
    prev = before;
    int save;
    int temp1;
    for(int i=0;before->next != NULL;i++)
    {
        save = before->next->elem;
        prev = prev->prev;
        while(prev->elem > save)
        {
            temp1 = prev->elem;
            before->next->elem = temp1;
            prev->elem = save;
        }
    }
}

void selection_sort(SetType* list) //정렬 필요한 배열, 현재배열 원소의 개수 전달
{
    int least, temp;
    DListNode* node = list->H;
    DListNode* change = list->H;
    DListNode* before = list->H;
    change = change->next;
    node = node->next;
    int rem;
    for(int i=0;node->next != NULL;i++)
    {
        least = node->elem;
        rem = node->elem;
        before = node;
        for(int i=0;before->next != NULL;i++)
        {
            before= before->next;
            if(before->elem<least)
            {
                least = change->elem;
                change=before;
            }
        }
        node->elem = least;
        change->element = rem;
        node= node->next;
    }
}

void initSet(DListNode* n)
{
    n->elem=NULL;
    n->next = NULL;
    n->prev = NULL;
}


int main()
{
    SetType* s1 = (SetType*)malloc(sizeof(SetType));
    initSet(s1);
    SetType* s2 = (SetType*)malloc(sizeof(SetType));
    initSet(s1);
    initNode(s1, s2);

    printf("원소 갯수 입력 \n");
    int num;
    scanf("%d",&num);

    for(int i=0;i<num;i++)
    {
        int n;
        scanf("%d",&n);
        addLast(s1,n);
    }

    printList(s1);
    insertion_sort(s1);
    selection_sort
}
