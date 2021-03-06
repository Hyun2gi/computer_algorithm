#include <stdio.h>
#include <stdlib.h>

#define MAX_ELEMENT 100

typedef struct
{
    int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;

void init(HeapType *h)
{
    h->heap_size = 0;
}


void upHeap(HeapType *h)
{
    int i = h->heap_size;
    int key = h->heap[i];

    while((i != 1)&&(key <h->heap[i/2]))
    {
        h->heap[i] = h->heap[i/2];
        i /= 2;
    }
    h->heap[i] = key;
}

void downHeap(HeapType *h)
{
    int temp = h->heap[1]; //downHeap할걸 temp에 넣어두기.
    int parent = 1, child = 2;

    while(child <= h->heap_size) //1번 체크
    {
        if((child < h->heap_size) && (h->heap[child] > h->heap[child+1])) //child == h->heap_size면 내가 맨 마지막 노드, 3번 체크가 여기서
            child++; // 오른쪽이 더 작으면
        if(temp <= h->heap[child])
            break;
        h->heap[parent] = h->heap[child];
        parent = child;
        child *= 2;
    }
    h->heap[parent] = temp;
}

void insert_Item(HeapType *h, int key)
{
    h->heap_size += 1;
    h->heap[h->heap_size] = key;
    upHeap(h);
}


int removeMin(HeapType *h)
{
    int key = h->heap[1];
    h->heap[1] = h->heap[h->heap_size]; //last를 넣어주기.
    h->heap_size-=1; //heap_size를 하나 감소시키기
    downHeap(h);
    return key; //key값을 리턴
}

void print_heap(HeapType *h)
{
    for(int i = 1; i<= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}

void heapSort(HeapType *h, int list[])
{
    HeapType heap;
    init(&heap);
    for(int i=1; i <= h->heap_size; i++)
    {
        heap.heap[i] = h->heap[i];
        heap.heap_size++;
    }

    for(int i=1; i <= h->heap_size; i++)
        list[i] = removeMin(&heap);
}

void printArray(int list[], int n)
{
    for(int i=1; i<=n;i++)
        printf("[%d] ", list[i]);
    printf("\n");
}

void inPlaceHeapSort(HeapType* h)
{
    int size = h->heap_size;
    int key;
    for(int i=0; i < size;i++)
    {
        key = removeMin(h);
        h->heap[h->heap_size + 1] = key;
    }
}

int main()
{
    HeapType heap;
    int list[MAX_ELEMENT] = {0};
    srand(time(NULL));
    init(&heap);
    for(int i=0; i < 15; i++)
        insert_Item(&heap, rand()%100);
    print_heap(&heap);
    inPlaceHeapSort(&heap);
    for(int i=1;heap.heap[i]>0;i++)
        printf("[%d]", heap.heap[i]);
}
