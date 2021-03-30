#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
    int data;
    struct ListNode* next;
}ListNode;

typedef struct
{
    ListNode* head;
}LinkedListType;

void init(LinkedListType* L)
{
    L->head = NULL;
}

LinkedListType* buildList(int n)
{
    ListNode* p = (ListNode*)malloc(sizeof(ListNode));
    LinkedListType* L=(LinkedListType*)malloc(sizeof(LinkedListType));
    L -> head = p;
    p -> data = 1;
    for(int i=2;i<n+1;i++)
    {
        p -> next = (ListNode*)malloc(sizeof(ListNode));
        p = p -> next;
        p -> data = i;
    }
    p->next = L->head;
    return L;
}

int candle(LinkedListType* L,int n, int k)
{
    L= buildList(n);
    return runSimulation(L,n,k);
}

int runSimulation(LinkedListType* L, int n, int k)
{
    ListNode *p = L->head;
    ListNode *pnext;
    while(p != p->next)
    {
        for(int i=1;i<k;i++)
            p = p->next;
        pnext = p->next;
        p->next=p->next->next;
        free(pnext);
        p = p->next;
    }
    return p->data;
}


int main()
{
    LinkedListType list;
    init(&list);
    int n;
    int k;
    printf("n과 k를 입력하세요.\n");
    printf("n 입력 : ");
    scanf("%d",&n);
    printf("k 입력 : ");
    scanf("%d",&k);
    int result = candle(&list,n,k);
    printf("위치는 %d이다.",result);
}
