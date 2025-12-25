#include <cstdio>
using namespace std;
int n;

// 直接初始化顺序表
int* initArray(int x) {
    return new int[x];
}

// 初始化顺序表 同时将所有元素赋值为 val
int* initArray(int x, int val) {
    int *a = new int[x];
    for (int i = 0; i < x; i++)
        a[i] = val;
    return a;
}

// 在 pos 位置插入值为 val 的元素（若是超出，直接丢失尾部数据）
void insert(int *a, int pos, int val) {
    for (int i = n; i > pos; i--)
        a[i] = a[i - 1];
    a[pos] = val;
}

// 删除 pos 位置的元素
void del(int *a, int pos) {
    for (int i = pos; i < n; i++)
        a[i] = a[i + 1];
}

// 查找下标为 pos 的 val 值
int find(int *a, int pos)
{
    if (pos >= n || pos < 0) return -1;  // 防越界
    return a[pos];
}

// 查找 val 值的下标，存在返回下标，不存在返回 -1
int find(int *a, int val)
{
    for (int i = 0; i < n; i++)
        if (a[i] == val)
            return i;
    return -1;
}