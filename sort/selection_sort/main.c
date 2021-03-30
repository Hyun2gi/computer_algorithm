#include <stdio.h>
#include <stdlib.h>
#include <time.h> //time(NULL) �������
#include <Windows.h> //sleep�Լ��� ����ϱ� ����
#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x),(x) = (y), (y) = (t))

void selection_sort(int list[], int n) //���� �ʿ��� �迭, ����迭 ������ ���� ����
{
    int least, temp; //least = min location
    for(int i=0; i<n-1;i++) //n-2���� �ݺ��ϰ� ��.
    {
        least = i;
        for(int j=i+1;j<n - 1;j++)
            if(list[j] < list[least])
                least=j;
        SWAP(list[i], list[least],temp);
    }
}

void main()
{
    //������ ���� ������ ���̴�.
    int list[MAX_SIZE];
    srand(time(NULL)); //random��������� srand�Լ� ���� ����

    for(int i=0;i<MAX_SIZE;i++)
    {
        list[i]=rand()%100; //0���� 99���� ���� �߻�
        for(int j=0;j<i;j++)
            if(list[i] == list[j]) //�ߺ�����
            i--;
    }

    for(int i=0;i<MAX_SIZE;i++)
        printf("%d ", list[i]);
    printf("\n\n"); getch();

    selection_sort(list,MAX_SIZE);

    for(int i=0; i< MAX_SIZE;i++)
    {
        printf("%d ",list[i]);
        Sleep(500);
    }

    printf("\n\n");
}
