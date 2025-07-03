// 二维前缀和模板
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define il inline
const int N = 1005;
int n, m, a[N][N], s[N][N];

//获取当前位置累加和
il int get(int i, int j)
{
    return i < 0 || j < 0 ? 0 : s[i][j];
}

//构建二维前缀和数组
//计算公式：当前位置和 = 左边前缀和 + 上面前缀和 - 左上前缀和 + 自己
/*
原理：
左边前缀和 = 左上前缀和 + 当前行的一维前缀和
上面前缀和 = 左上前缀和 + 当前列的一维前缀和
实际当前位置二维前缀和 = 当行一维前缀和 + 当列一维前缀和 + 左上二维前缀和 + 自己
*/
il void build()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            s[i][j] = get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1) + a[i][j];
}

//传递矩形四个角的坐标获取前缀和
il int sum(int x1, int y1, int x2, int y2) 
{
    return get(x2, y2) - get(x1 - 1, y2) - get(x2, y1 - 1) + get(x1 - 1, y1 - 1);
}


int main()
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);


    return 0;
}