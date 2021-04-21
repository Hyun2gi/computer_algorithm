#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 100

typedef struct
{   int heap[MAX_ELEMENT];
    int heap_size;
}HeapType;



typedef struct
{   int stack[MAX_ELEMENT];
    int top;
}Stack;



void init_heap(HeapType *h)
{
    h->heap_size=0;
}



void init_stack(Stack *s)
{
    s->top=-1;
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



void insert_Item(HeapType *h, int key)
{
    h->heap_size += 1;
    h->heap[h->heap_size] = key;
    upHeap(h);
}



void print_heap(HeapType *h)
{
    for(int i = 1; i<= h->heap_size; i++)
        printf("[%d] ", h->heap[i]);
    printf("\n");
}



int IsEmpty(Stack*s){
    if(s->top<0)
        return 1;
    else
        return 0;
}



void push(int value, Stack *s){
    s->stack[++(s->top)] = value;
}


int pop(Stack *s){
        return s->stack[(s->top)--];
}


void binaryExpansion(int i, Stack *s)
{
    while(i>=2)
    {
        push(i%2, s);
        i=i/2;
    }
    push(i,s);
}



int findLastNode(HeapType *h, int n)
{

    Stack s;
    init_stack(&s);
    int v=1;
    binaryExpansion(n,&s);
    pop(&s);
    int bit;
    while(!IsEmpty(&s))
    {
        bit = pop(&s);
        if(bit==0)
        {
            v = v*2;
        }else {
            v = v*2+1;
        }
    }
    return h->heap[v];

}


int main()
{
    HeapType h;
   init_heap(&h);
   insert_Item(&h, 10);
   insert_Item(&h, 6);
   insert_Item(&h, 4);
   insert_Item(&h, 14);
   insert_Item(&h, 9);
   insert_Item(&h, 12);
   insert_Item(&h, 2);
   insert_Item(&h, 5);
   insert_Item(&h, 11);
   insert_Item(&h, 9);

    print_heap(&h);


    int last = findLastNode(&h,10);
    printf("last node : %d", last);

}
