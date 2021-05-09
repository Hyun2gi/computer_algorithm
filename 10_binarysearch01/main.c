#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 15

typedef struct
{
    int key; //키
    char value[10]; //값, 항목값
}element;

typedef struct
{
    element dict[SIZE]; //element 배열로 dictionary를 만들기
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
            d->dict[i].value[j] = rand() % 26 + 97; //해당되는 ascii코드 만들기
        d->size++;
    }
}

void makeDict(DictType* d)
{
    insertKey(d); //key값 발생
    insertValue(d); //value값발생
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

int FindElement(DictType* d, int key, int l, int r) //반복문
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

element removeElement(DictType* d, int key) //삭제되어질것을 return
{
    int index = FindElement(d, key,0,d->size-1); //삭제될 key에 대한 index
    if(index == -1)
    {
        printf("삭제할 요소가 없습니다.\n");
        return;
    }
    else
    {
        element item = d->dict[index]; //해당 index item으로 받아오기
        for(int i=index; i<d->size-1;i++)
            d->dict[i] = d->dict[i+1]; //왼쪽으로 shift
        d->size--;
        return item;
    }
}



int main()
{
    DictType d; //dict 선언
    init(&d);
    srand(time(NULL)); //난수발생
    makeDict(&d);
    printDict(&d);
    getchar();
    printf("\n");
    insertion_sort(&d);
    printDict(&d);
    getchar();


    printf("\n검색할 키값을 입력 : ");
    int key;
    scanf_s("%d", &key);
    int index = rFindElement(&d, key, 0, SIZE-1);
    if(index == -1)
        printf("\n검색에 실패하였음\n");
    else
    {
        printf("\n위치 %d에서 키 : %d, 값 :",index + 1, key);
        for(int j = 0; j<5;j++)
            printf("%c",d.dict[index].value[j]);
        printf("이 검색되었음\n");
    }

    return 0;
}
