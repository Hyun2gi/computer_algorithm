#include <stdio.h>
#include <stdlib.h>
#include <time.h> //time(NULL) 사용위해
#include <Windows.h> //sleep함수를 사용하기 위해
#define MAX_SIZE 15
#define SWAP(x,y,t) ((t) = (x),(x) = (y), (y) = (t))

void selection_sort(int list[], int n) //정렬 필요한 배열, 현재배열 원소의 개수 전달
{
    int least, temp; //least = min location
    for(int i=0; i<n-1;i++) //n-2까지 반복하게 됨.
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
    //임의의 수를 저장할 것이다.
    int list[MAX_SIZE];
    srand(time(NULL)); //random수사용위해 srand함수 먼저 선언

    for(int i=0;i<MAX_SIZE;i++)
    {
        list[i]=rand()%100; //0부터 99까지 난수 발생
        for(int j=0;j<i;j++)
            if(list[i] == list[j]) //중복제거
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
