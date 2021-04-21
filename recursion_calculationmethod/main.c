#include <stdio.h>
#include <stdlib.h>

int product(int a, int b)
{
    if(b==1)
        return a;
    else
        return a+product(a,b-1);
}

int modulo(int a, int b)
{
    if(a<b)
        return a;
    else
        return modulo(a-b,b);
}

int quotient(int a,int b)
{
    if(a < b)
        return 0;
    else
        return 1+quotient(a-b,b);
}

int main()
{
    int a,b,c;
    a = product(2,3);
    b = modulo(8,3);
    c = quotient(13,3);
    printf("%d\n%d\n%d\n", a, b,c);
}
