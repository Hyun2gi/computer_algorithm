#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int V[SIZE];
    int n;
}ArrayList;

void init(ArrayList* L) //초기화
{
    L->n = 0;
}

void traverse(ArrayList *L) //접근
{
    for(int i=0;i < L->n ;i++)
        printf("[%d]" , L->V[i]);
    printf("\n");
}

void add(ArrayList* L, int pos, int item)
{
    if(L->n == SIZE) //예외처리, 별도의 함수처리하는게 더 좋음.
    {
        printf("fullListException...\n");
        exit(1);
    }
    //invalidPosException....... 0<= pos <= L->n

    for(int i = L->n - 1;i>=pos;i--) //삽입할려는 index까지
        L->V[i+1] = L->V[i]; //한칸씩 오른쪽으로 위치이동
    L->V[pos] = item;
    L->n++; //element 한 개 증가
}

int remove1(ArrayList* L, int pos)
{
    //exception
    int item = L->V[pos];
    for(int i = pos+1; i<=L->n-1;i++) //삭제할려는 곳 한칸 오른쪽부터 오른쪽거를 한칸 왼쪽으로...
    L->V[i-1] = L->V[i];
    L->n--;
    return item;
}

int main()
{
    ArrayList list;

    init(&list);

    add(&list, 0, 10); traverse(&list);
    add(&list, 0, 20); traverse(&list);
    add(&list, 1, 30); traverse(&list);
    add(&list, 1, 40); traverse(&list);
    add(&list, 3, 50); traverse(&list);

    getchar();
    remove1(&list, 1); traverse(&list);
    remove1(&list, 2); traverse(&list);
}
