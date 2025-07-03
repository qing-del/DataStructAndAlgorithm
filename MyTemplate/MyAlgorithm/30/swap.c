#include <stdio.h>

//交换算法（异或运算）
void swap(int* a, int* b)
{
    if(*a==*b) return;
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}