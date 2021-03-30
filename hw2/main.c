#include <stdio.h>
#include <stdlib.h>

int candle(int n, int k)
{
    int list[n];
    buildList(list,n);
    return runSimulation(list,n,k);
}

void buildList(int A[], int n)
{
    for(int r=0;r<n-1;r++)
        A[r]=r+1;
}

int runSimulation(int A[], int n, int k)
{
    int N=n;
    int r=0;
    while(n>1)
    {
        int i=0;
        while(i<k)
        {
            r=(r+1)%N;
            if(A[r] != 0)
                i=i+1;
        }
        A[r]=0;
        n = n-1;
        while(A[r]==0)
            r=(r+1)%N;
    }
    return A[r];
}

int main()
{
    int n;
    int k;
    printf("n과 k를 입력하세요.\n");
    printf("n 입력 : ");
    scanf("%d",&n);
    printf("k 입력 : ");
    scanf("%d",&k);
    int result = candle(n,k);
    printf("위치는 %d이다.",result);
}
