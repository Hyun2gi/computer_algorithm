//트리구현
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define SIZE 6
#define MAX 100


typedef int element;
typedef struct {
   element data[MAX];
   int top;
}StackType;

void init(StackType* s) {
   s->top = -1;
}

int is_empty(StackType* s) {
   return(s->top == -1);
}

int is_full(StackType* s) {
   return(s->top == (MAX - 1));
}

void push(StackType* s, element item) {
   if (is_full(s))
      exit(1);
   else {
      s->data[++s->top] = item;
   }
}

element pop(StackType* s) {
   if (is_empty(s))
      exit(1);
   int element = s->data[s->top--];
   return element;
}

element peek(StackType* s) {
   if (is_empty(s))
      exit(1);
   int k = s->top;
   return s->data[k];
}

void stack_print(StackType* s) {
   for (int i = 0;i <= s->top;i++)
      printf("[%d] ", s->data[i]);
   printf("\n");
}


void spans2(StackType *X, StackType* S, int n) {
   StackType* A=(StackType*)malloc(sizeof(StackType));
   init(A);

   for (int i = 0;i < n;i++) {
      while (!is_empty(A) && (X->data[A->data[A->top]] <= X->data[i])) {
         pop(A);
      }
      if (is_empty(A))
         push(S, i + 1);
      else {
         push(S, i - A->data[A->top]);
      }
      push(A, i);
      printf("[i:%d]A : ", i);
      stack_print(A);
   }
   while (!is_empty(A))
      pop(A);

}

int spans(int X[], int S[])
{
    int s;
    for(int i = 0; i < SIZE; i++)
    {
        s = 1;
        while((s <= i) && (X[i - s] <= X[i]))
            s++;
        S[i] = s;
    }
}

int main(void)
{
    /*
   StackType X;
   StackType S;
   init(&X); init(&S);

   push(&X, 60); push(&X, 30); push(&X, 40); push(&X, 20); push(&X, 50); push(&X, 30);
   printf("X: ");
   stack_print(&X);
   printf("\n");
   spans2(&X, &S, 6);

   printf("S: ");
   stack_print(&S);
    */

    int X[SIZE] = {6,3,4,2,5,3};
    int S[SIZE] = {0};

    spans(X,S);

    for(int i=0; i< SIZE; i++)
        printf("[%d] ", S[i]);
    printf("\n");
}
