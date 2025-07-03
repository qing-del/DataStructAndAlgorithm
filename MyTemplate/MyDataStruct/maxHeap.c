#include <stdio.h>
//表示堆可以存放的数据类型
#define Type int
#define MAXN (int)1e5+10

int Heap[MAXN]; //大根堆
int Size;

void swap(Type* a,Type* b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

//堆调整（传入下标）（向下）
void HeapFy(int x)
{
    int l= (x<<1)+1;    //先获取左孩子
    if(l>=Size) return; //越界了直接返回
    l= l+1<Size && Heap[l]<Heap[l+1]? l+1:l; //获取最优秀的孩子
    l= Heap[x]<Heap[l]? l:x;   //获取最优结果
    if(l!=x)
    {
        swap(&Heap[l], &Heap[x]);
        HeapFy(l);   //递归实现多层调整
    }
}

//插入函数
void insert(Type x)
{
    Heap[Size++] = x;
    int index = Size - 1;
    if (Heap[index] > Heap[(index - 1) / 2])   //比根节点小
    {
        swap(&Heap[index], &Heap[(index - 1) / 2]);
        index = (index - 1) >> 1;
        while (Heap[index] > Heap[(index - 1) / 2])
        {
            swap(&Heap[index], &Heap[(index - 1) / 2]);
            index = (index - 1) >> 1;
        }
    }
    else
        HeapFy(index);
}

//弹出函数（并返回顶部的值）（有函数保护）
Type getAndPop()
{
    if (!Size) {
        printf("heap is empty!\n");
        return -1;
    }
    Type res = Heap[0];
    swap(&Heap[0], &Heap[--Size]);
    HeapFy(0);
    return res;
}

//弹出堆顶函数（无保护）
void pop() {
    swap(&Heap[0], &Heap[--Size]);
    HeapFy(0);
}

//无保护获取顶元素
Type xtop() {
    return Heap[0];
}

//获取堆顶元素
Type top() {
    if (!Size) {
        printf("heap is empty!\n");
        return -1;
    }
    return Heap[0];
}