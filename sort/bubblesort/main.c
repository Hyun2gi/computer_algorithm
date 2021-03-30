#include <stdio.h>
#include <stdlib.h>
#define SWAP(x,y,t) ((t) = (x),(x) = (y), (y) = (t))

//버블정렬은 인접한 두 개를 비교해서 크기가 순서대로 되어있지않으면 서로 교환해서 끝까지 진행.
/*
이게 한 단계(일단계)
5 3 8 1 2 7
3 5 8 1 2 7
3 5 1 8 2 7
3 5 1 2 8 7
3 5 1 2 7 8
*/

//오른쪽 끝부터 정렬된다.
void bubble_sort(int list[], int n)
{
    int temp;
    printf("정렬할 원소 : ");
    for(int t=0; t < n; t++)
        printf("%d", list[t]);
    printf("\n\n<<<<<<<<<<<<<<<버블 정렬 수행>>>>>>>>>>>>>>>>>>>>>");

    for(int i = n-1; i > 0;i--)
    {
        printf("\n %d 단계>> \n", n-i);
        for(int j=0; j < i; j++)
            if(list[j]>list[j+1])
                SWAP(list[j], list[j+1], temp);

        for(int t=0;t < n; t++)
            printf("%3d", list[t]);

        printf("\n");
    }
}


void main()
{
    int list[6] = {5, 3, 8, 1, 2, 7};
    bubble_sort(list, 6);
}

