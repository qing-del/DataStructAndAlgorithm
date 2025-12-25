// 测试链接 : https://leetcode.cn/problems/bricks-falling-when-hit/
// 有一个用法 ： 时光倒流 ⭐⭐
// 1） 要被击打砖块的位置 -1
// 2） 把跟天花板连接的都填充成 2
// 3） 倒序恢复被击打的砖块 然后检查上下左右有没有 2 有的话就进行填充 2 计算填充的数量cnt， 结果为 cnt-1
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m, hs, cnt;
    void dfs(int i, int j, vector<vector<int>>& g)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || g[i][j] != 1) return;
        g[i][j] = 2, cnt++;
        dfs(i - 1, j, g);
        dfs(i + 1, j, g);
        dfs(i, j - 1, g);
        dfs(i, j + 1, g);
    }
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        n = grid.size(), m = grid[0].size(), hs = hits.size(), cnt = 0;
        int i, ui, uj;
        for (i = 0; i < hs; i++) grid[hits[i][0]][hits[i][1]]--;
        for (i = 0; i < m; i++) if (grid[0][i] == 1) dfs(0, i, grid);
        vector<int> ans(hs, 0);
        for (i = hs - 1; i >= 0; i--)
        {
            cnt = 0;
            ui = hits[i][0], uj = hits[i][1];
            grid[ui][uj]++;
            if ((ui - 1 >= 0 && grid[ui - 1][uj] == 2) ||
                (ui + 1 < n && grid[ui + 1][uj] == 2) ||
                (uj - 1 >= 0 && grid[ui][uj - 1] == 2) ||
                (uj + 1 < m && grid[ui][uj + 1] == 2) ||
                ui == 0) {
                dfs(ui, uj, grid);
                ans[i] = max(0, cnt - 1);
            }
        }
        return ans;
    }
};

/*
grid =
[[1],[1],[1],[1],[1]]

hits =
[[3,0],[4,0],[1,0],[2,0],[0,0]]
*/
int main() {
    vector<vector<int>> grid = {{1},{1},{1},{1},{1}};
    vector<vector<int>> hits = {{3,0},{4,0},{1,0},{2,0},{0,0}};

    Solution s;
    cout << s.hitBricks(grid, hits) << endl;
    return 0;
}