//测试连接：https://leetcode.cn/problems/largest-1-bordered-square/
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'

class Solution {
    const static int N = 1e2 + 10;
    int n, m;
    int s[N][N];
    static int Min(int a, int b) { return a < b ? a : b; }
    int get(int i, int j) 
    {
        return i < 0 || j < 0 ? 0 : s[i][j];
    }
    void init(vector<vector<int>>& grid)
    {
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                s[i][j] = get(i - 1, j) + get(i, j - 1) - get(i - 1, j - 1) + grid[i][j];
    }
    int sum(int x1, int y1, int x2, int y2)
    {
        if (x1 < 0 || y1 < 0 || x1 < x2 || y1 < y2) return 0;   //2-error
        return get(x1, y1) - get(x2 - 1, y1) - get(x1, y2 - 1) + get(x2 - 1, y2 - 1);
    }
    int solve()
    {
        int ans = Min(n, m);
        while (ans)
        {
            int cor;    //1-error
            if (ans == 1)
                cor = 1;
            else if (ans == 2)
                cor = 4;
            else
                cor = 2 * ans + 2 * (ans - 2);

            for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++)
                {
                    if (i + ans > n || j + ans > m) continue;
                    int sum1 = sum(i + ans - 1, j + ans - 1, i, j);
                    int sum2 = sum(i + ans - 2, j + ans - 2, i + 1, j + 1);
                    if (sum1 - sum2 == cor) return ans * ans;
                }
            ans--;
        }
        return ans;
    }
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) 
    {
        init(grid);
        return solve();
    }
};