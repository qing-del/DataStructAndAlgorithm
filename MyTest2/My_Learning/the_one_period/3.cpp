#include <stdio.h>

int main()
{
    int * x;
    int a = 12;
    x = &a;
    a = 23;
    *x = 24;

    printf("%d",*x);
    printf("\n%p",x);

    return 0;
}