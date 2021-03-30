#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t) = (x),(x) = (y), (y) = (t))

#define MAX_SIZE 15

void shell_sort(int list[], int n)
{
    int i, gap;
    for(gap = n/2; gap>0; gap=gap/2)
    {
        if(gap%2 == 0) //gap�� ¦���̸� Ȧ���� ������ֱ�
            gap++;
        for(i=0; i<gap;i++)
            inc_insertion_sort(list, i, n-1, gap); //i�� ���� index, n-1�� ������ index, gap�� gap
    }
}

void inc_insertion_sort(int list[], int first, int last, int gap) //gap��ŭ ��ġ�̵��ؾ��ϴϱ�
{
    int i, j, key;
    for(i = first + gap; i <= last; i = i+gap)
    {
        key = list[i];
        for(j = i-gap; j>= first && list[j]>key;j = j-gap) //���� gap�� 5��.. 0 index���� �����ؾ��ϴϱ� i-gap����
            list[j+gap]=list[j];
        list[j+gap] = key;
    }
}

void main()
{
    int list[MAX_SIZE];
    srand(time(NULL));

    for(int i=0;i<MAX_SIZE;i++)
    {
        list[i]=rand()%100;
        for(int j=0;j<i;j++)
            if(list[i] == list[j])
            i--;
    }

    for(int i=0;i<MAX_SIZE;i++)
        printf("%d ", list[i]);
    printf("\n\n"); getch();

    shell_sort(list, MAX_SIZE);
    for(int i=0; i< MAX_SIZE;i++)
    {
        printf("%d ",list[i]);
        Sleep(500);
    }

    printf("\n\n");
}
