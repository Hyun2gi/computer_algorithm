#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define ROWS 8
#define COLS 8

void makeArray(int A[][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        int count = rand() % 8;
        for(int i = 0; i < count; i++)
            A[r][i] = 1;
        for(int j = count; j < COLS; j++)
            A[r][j] = 0;
    }
}

void printArray(int A[][COLS])
{
    for(int r = 0; r < ROWS; r++)
    {
        for(int c = 0; c <COLS; c++)
            printf("%2d ", A[r][c]);
        printf("\n");
    }
}

int findRow(int A[], int key)
{
    for(int c = 0; c < COLS; c++)
        if(A[c] == key)
            return c;
    return -1;
}

int findMatrix(int A[][COLS], int key)
{
    int r = 0;
    int index;

    while(r < ROWS)
    {
        index = findRow(A[r], key);
        if(index >= 0)
        {
            printf("%d행 %d열에서 %d 발견\n", r, index, key);
            return;
        }
        else
            r++;
    }
    printf("Not Found\n");
}

void mostOnesButSlow(int A[][COLS])
{
     int jmax = 0;
     int i, j, row;
     for(i=0;i < ROWS; i++)
     {
         j = 0;
         while(j < COLS && A[i][j] == 1)
            j++;
         if(j > jmax)
         {
             row = i;
             jmax = j;
         }
     }
     printf("%d행에 %d개의 1이 최대값임\n", row, jmax);
}

int mostOnes(int A[][COLS])
{
    int i = 0, j = 0;
    int row;

    while(1)
    {
        while(A[i][j] == 1)
        {
            j++;
            if(j == COLS - 1)
                return i;
        }
        row = i;
        while(A[i][j] == 0)
        {
            i++;
            if(i == COLS - 1)
                return row;
        }
    }
}

int main()
{
    int A[ROWS][COLS];
    srand(time(NULL));
    makeArray(A);
    printArray(A);
    getchar();

    printf("최대 1행은 %d행입니다. \n", mostOnes(A));
}
