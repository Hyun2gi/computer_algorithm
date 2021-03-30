#include <stdio.h>
#include <stdlib.h>

#define SIZE 6

void spans(int X[],int S[])
{
    int s;
    for(int i=0; i<SIZE; i++)
    {
        s=1; //자기 자신을 포함해야하니까
        while((s<=1) && (X[i-s] <= X[i])) {
            s++;
        }
        S[i] = s;
    }
}

int main()
{
    int X[SIZE] = {6,3,4,2,5,3}
    int S[SIZE] = {0};

    spans(X,S);
}
