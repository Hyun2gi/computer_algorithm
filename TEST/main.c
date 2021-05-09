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

    int i=0;

    while(i<10)
    {
        int a;
        printf("11~40까지의 임의의 수 입력 ");
        scanf("%d",&a);
        if(a<11 || a>40)
        {
            printf("다시 입력하세요.");
            continue;
        }else {
            addLast(&list,a);
            i++;
        }
    }
    free(&list);
    printList(&list);
}
