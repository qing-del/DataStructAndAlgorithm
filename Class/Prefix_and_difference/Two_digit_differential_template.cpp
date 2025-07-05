// 二维差分的模板

/* 二维区间内进行值的修改
例如类似操作：
给定一个左上角的坐标(x1,y1)和右下角的坐标(x2,y2)，
将[x1,y1]到[x2,y2]的区域内的值加上一个常数c */

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
const int N = 1e5 + 10;
int n, m;
int a[N][N], s[N][N];
int get(int i, int j) { return i < 0 || j < 0 ? 0 : s[i][j]; }

// 区间修改：
/* 左上角 ＆ 右下角 的值要先增加一个val
左下角 ＆ 右上角 值要先减去一个val */
void add(int x1, int y1, int x2, int y2, int c)
{
    s[x1][y1] += c;         // 左上角
    s[x2 + 1][y2 + 1] += c; // 右下角
    s[x1][y2 + 1] -= c;     // 右上角
    s[x2 + 1][y1] -= c;     // 左下角
}

// 修改完成之后进行加工 变成 区间和（即为单点的值）
//利用二维区间构建前缀和的方式进行 构建数组
void build()
{
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            s[i][j] = get(i,j) + get(i-1,j) + get(i,j-1) - get(i-1,j-1);
}

// 区间单点查询
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    build();
    int q; cin>> q; // 查询次数
    while(q--)
    {
        int x, y; cin >> x >> y;
        cout << get(x, y) << endl;
    }
    return 0;
}