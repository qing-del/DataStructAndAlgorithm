//测试链接：https://leetcode.cn/problems/stamping-the-grid/description/
// 这个是 二维差分 + 二维前缀和 的练习题 -- 邮票贴满网格
/* 题目只能用枚举每一个左上角点
可以使用二维前缀和优化查询的复杂度
需要开 2 个新的数组 采用 1 个数组存储原数组，1 个数组作为差分数组*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

//自己编写的AC代码（169ms）
class Solution {
    int n, m, h, w;
    vector<vector<int>> s;
    vector<vector<int>> d;

    int get(int i, int j, vector<vector<int>>& grid) { return i < 0 || j < 0 || i >= n || j >= m ? 0 : grid[i][j]; }
    int getSum(int x1, int y1, int x2, int y2, vector<vector<int>>& grid) {
        return get(x2, y2, s) - get(x1 - 1, y2, s) - get(x2, y1 - 1, s) + get(x1 - 1, y1 - 1, s);
    }

    //这个差分修改的条件语句 可以通过更改遍历的方式进行优化删除（待优化）
    void add(int x1, int y1, int x2, int y2)
    {
        d[x1][y1]++;
        if (x2 + 1 < n) d[x2 + 1][y1]--;
        if (y2 + 1 < m) d[x1][y2 + 1]--;
        if (x2 + 1 < n && y2 + 1 < m) d[x2 + 1][y2 + 1]++;
    }

    void solve()
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                d[i][j] += get(i - 1, j, d) + get(i, j - 1, d) - get(i - 1, j - 1, d);
    }

    bool check(vector<vector<int>>& grid)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 0 && d[i][j] == 0) return 0;
        return 1;
    }

public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth)
    {
        n = grid.size(), m = grid[0].size();
        h = stampHeight, w = stampWidth;
        s.resize(n, vector<int>(m, 0));
        d.resize(n, vector<int>(m, 0));

        //构建二维前缀和
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                s[i][j] = get(i, j - 1, s) + get(i - 1, j, s) - get(i - 1, j - 1, s) + grid[i][j];

        //这里的写法可以注意一下 abcd来计算很好
        for (int a = 0, c = a + h - 1; c < n; a++, c++)
            for (int b = 0, d = b + w - 1; d < m; b++, d++)
                if (getSum(a, b, c, d, grid) == 0)
                    add(a, b, c, d);

        solve();
        return check(grid);
    }
};

//题解里面的示例代码（17ms）
class Solution_2 {
public:
    bool possibleToStamp(vector<vector<int>>& grid, int stampHeight, int stampWidth) {
        int m = grid.size(), n = grid[0].size();
        //在 leetcode 中的编译器支持VLA的写法 可以使用下面的方式创建数组 但是在其他编译器中可能不支持
        int s[m + 1][n + 1]; //1. 计算grid的二维前缀和
        memset(s, 0, sizeof(s));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j] + grid[i][j];
        int d[m + 2][n + 2]; //2. 计算二维差分
        memset(d, 0, sizeof(d));
        for (int i2 = stampHeight; i2 <= m; i2++) {
            for (int j2 = stampWidth; j2 <= n; j2++) {
                int i1 = i2 - stampHeight + 1;
                int j1 = j2 - stampWidth + 1;
                if (s[i2][j2] - s[i2][j1 - 1] - s[i1 - 1][j2] + s[i1 - 1][j1 - 1] == 0) {
                    d[i1][j1]++;
                    d[i1][j2 + 1]--;
                    d[i2 + 1][j1]--;
                    d[i2 + 1][j2 + 1]++;
                }
            }
        }
        for (int i = 0; i < m; i++) { //3. 还原二维差分矩阵对应的计数矩阵（原地计算）
            for (int j = 0; j < n; j++) {
                d[i + 1][j + 1] += d[i + 1][j] + d[i][j + 1] - d[i][j];
                if (grid[i][j] == 0 && d[i + 1][j + 1] == 0)
                    return false;
            }
        }
        return true;
    }
};

//grid = [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]], stampHeight = 2, stampWidth = 2 
int main() {
    vector<vector<int>> grid = {
        {1,0,0,0},
        {0,1,0,0},
        {0,0,1,0},
        {0,0,0,1}
    };
    int stampHeight = 2;
    int stampWidth = 2;
    Solution sol;
    bool res = sol.possibleToStamp(grid, stampHeight, stampWidth);
    cout << (res ? "true" : "false") << endl;
    return 0;
}
