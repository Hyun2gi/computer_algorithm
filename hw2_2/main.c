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

void remove1(int A[],int n,int pos)
{
    for(int i=pos;i<n-1;i++)
        A[i]=A[i+1];
}

int runSimulation(int A[], int n, int k)
{
    int r=0;
    while(n>1)
    {
        r = (r+k)%n;
        remove1(A,n,r);
        n--;
    }
    return A[0];
}

int main()
{
    int n;
    int k;
    printf("n�� k�� �Է��ϼ���.\n");
    printf("n �Է� : ");
    scanf("%d",&n);
    printf("k �Է� : ");
    scanf("%d",&k);
    int result = candle(n,k);
    printf("��ġ�� %d�̴�.",result);
}

