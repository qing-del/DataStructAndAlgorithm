//堆排序
#include <stdio.h>
#define MAXN (int)1e5+10

int heap[MAXN];
int hs;
int a[MAXN];

void swap(int* a, int* b)
{
    *a=*a^*b;
    *b=*a^*b;
    *a=*a^*b;
}

void heapFy(int x)
{
    int l=x*2+1;
    if(l>=hs) return;
    l=l+1<hs && heap[l] < heap[l+1] ? l+1:l;
    l=heap[x]<heap[l] ? l:x;
    if(l!=x)
    {
        swap(&heap[l],&heap[x]);
        heapFy(l);
    }
}

int pop()
{
    int res=heap[0];
    swap(&heap[0],&heap[--hs]);
    heapFy(0);
    return res;
}

void heapSort(int* a, int n)
{
    hs=n;
    while(n--)
    {
        heap[n]=a[n];
        heapFy(heap[n]);
    }
    while(hs)
        a[n++]=pop();
}