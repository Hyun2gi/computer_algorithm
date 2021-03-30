#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

typedef struct
{
    int V[SIZE];
    int n;
}ArrayList;

void init(ArrayList* L) //�ʱ�ȭ
{
    L->n = 0;
}

void traverse(ArrayList *L) //����
{
    for(int i=0;i < L->n ;i++)
        printf("[%d]" , L->V[i]);
    printf("\n");
}

void add(ArrayList* L, int pos, int item)
{
    if(L->n == SIZE) //����ó��, ������ �Լ�ó���ϴ°� �� ����.
    {
        printf("fullListException...\n");
        exit(1);
    }
    //invalidPosException....... 0<= pos <= L->n

    for(int i = L->n - 1;i>=pos;i--) //�����ҷ��� index����
        L->V[i+1] = L->V[i]; //��ĭ�� ���������� ��ġ�̵�
    L->V[pos] = item;
    L->n++; //element �� �� ����
}

int remove1(ArrayList* L, int pos)
{
    //exception
    int item = L->V[pos];
    for(int i = pos+1; i<=L->n-1;i++) //�����ҷ��� �� ��ĭ �����ʺ��� �����ʰŸ� ��ĭ ��������...
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
