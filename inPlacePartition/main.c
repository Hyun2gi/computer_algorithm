#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 15
#define SWAP(x, y, t) ((t) = (x), (x) = (y), (y) = (t))

int partition(int list[], int left, int right, int k)
{
    int pivot, temp, low, high; //temp는 swap를 위해

    pivot = list[k];
    SWAP(list[k], list[right], temp);

    printf("Pivot = %d\n", pivot);
    for(int i=0; i< MAX_SIZE;i++)
        printf("[%d] ", list[i]);
    printf("\n\n");


    //low는 왼쪽으로 움직인다음, high는 오른쪽으로 움직인 다음에

    low = left - 1;
    high = right;

    do
    {
        do
            low++;
        while(list[low] < pivot);

        do
            high--;
        while(list[high] > pivot);


        for(int i=0; i< MAX_SIZE; i++)
            printf("[%d] ", list[i]);
        printf("\nlow = %d, high = %d\n", low, high);

        if(low < high)
            SWAP(list[low], list[high], temp);

    }while(low < high);

    SWAP(list[low], list[right], temp); //high는 pivot보다 작은 애 중에 가장 오른쪽에 있다.
    return low;//pivot이 위치되어있는 걸 q가 받음.

}

void quick_sort(int list[], int left, int right)
{
    if(left < right)
    {
        // 0부터 잘리는 경우, pivot을 오른쪽부터 잘리는 경우가 있을까봐 left를 더해줌
        int k = rand() % (right - left)+left + 1; //추가, 전체 배열에서 임의의 index
        int q = partition(list, left, right, k);
        quick_sort(list, left, q-1); //왼쪽 서브, q는 분할에서 빠져야함. 정렬이 이미 된 아이.
        quick_sort(list, q+1, right); //오른쪽 서브
    }
}

int main()
{
    int list[MAX_SIZE];
    srand(time(NULL));
    for(int i=0; i < MAX_SIZE; i++)
        list[i] = rand() % 100;
    for(int i=0; i< MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n");

    quick_sort(list, 0, MAX_SIZE - 1);

    for(int i=0; i< MAX_SIZE; i++)
        printf("[%d] ", list[i]);
    printf("\n\n");

    return 0;
}
