#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

typedef struct
{
    int key; //Ű
    char value[10]; //��, �׸�
}element;

typedef struct
{
    element dict[SIZE]; //element �迭�� dictionary�� �����
    int size;
}DictType;

void init(DictType* d)
{
    d->size = 0;
}


void insertKey(DictType* d)
{
    for(int i=0; i < SIZE; i++)
    {
        d->dict[i].key = rand()%30 + 1;
        for(int j=0;j<i;j++)
            if(d->dict[i].key == d->dict[j].key)
                i--;
    }
}

void insertion_sort(DictType* d)
{
    int i,j;
    element item;
    for(i = 1; i <SIZE;i++)
    {
        item = d->dict[i];
        for(j = i-1; j >= 0 && d->dict[j].key > item.key;j--)
            d->dict[j+1] = d->dict[j];
        d->dict[j+1] = item;
    }
}



void insertValue(DictType* d)
{
    for(int i=0; i < SIZE; i++)
    {
        for(int j=0; j < 5;j++)
            d->dict[i].value[j] = rand() % 26 + 97; //�ش�Ǵ� ascii�ڵ� �����
        d->size++;
    }
}

void makeDict(DictType* d)
{
    insertKey(d); //key�� �߻�
    insertValue(d); //value���߻�
}


void printDict(DictType* d)
{
    printf("key value \n================\n");
    for(int i=0; i < d->size;i++)
    {
        printf("%2d ", d->dict[i].key);
        for(int j=0; i < d->size;i++)
            printf("%c", d->dict[i].value[j]);
        printf("\n");
    }
}

int FindElement(DictType* d, int key, int l, int r) //�ݺ���
{
    int mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(key == d->dict[mid].key)
            return mid;
        else if(key < d->dict[mid].key)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}

int rFindElement(DictType* d, int key, int l, int r) //recursiveFindElement
{
    int mid;
    while(l <= r)
    {
        mid = (l+r)/2;
        if(key == d->dict[mid].key)
            return mid;
        else if(key < d->dict[mid].key)
            return rFindElement(d, key,l,mid-1);
        else
            return rFindElement(d, key, mid+1,r);
    }
    return -1;
}

element removeElement(DictType* d, int key) //�����Ǿ������� return
{
    int index = FindElement(d, key,0,d->size-1); //������ key�� ���� index
    if(index == -1)
    {
        printf("������ ��Ұ� �����ϴ�.\n");
        return;
    }
    else
    {
        element item = d->dict[index]; //�ش� index item���� �޾ƿ���
        for(int i=index; i<d->size-1;i++)
            d->dict[i] = d->dict[i+1]; //�������� shift
        d->size--;
        return item;
    }
}



int main()
{
    DictType d; //dict ����
    init(&d);
    srand(time(NULL)); //�����߻�
    makeDict(&d);
    printDict(&d);
    getchar();
    printf("\n");
    insertion_sort(&d);
    printDict(&d);
    getchar();


    printf("\n�˻��� Ű���� �Է� : ");
    int key;
    scanf_s("%d", &key);
    int index = rFindElement(&d, key, 0, SIZE-1);
    if(index == -1)
        printf("\n�˻��� �����Ͽ���\n");
    else
    {
        printf("\n��ġ %d���� Ű : %d, �� :",index + 1, key);
        for(int j = 0; j<5;j++)
            printf("%c",d.dict[index].value[j]);
        printf("�� �˻��Ǿ���\n");
    }

    return 0;
}
