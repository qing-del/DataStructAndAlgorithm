// 最大人工岛
// 本题的学习是一些优化方法 ⭐
// 测试链接 : https://leetcode.cn/problems/making-a-large-island/
#include <bits/stdc++.h>
using namespace std;

int n, cnt;
int Max(int a, int b) { return a > b ? a : b; }
class Solution {
    void dfs(int i, int j, vector<vector<int>>& g)
    {
        g[i][j] = cnt;
        if (i - 1 >= 0 && g[i - 1][j] == 1) dfs(i - 1, j, g);
        if (i + 1 < n && g[i + 1][j] == 1) dfs(i + 1, j, g);
        if (j - 1 >= 0 && g[i][j - 1] == 1) dfs(i, j - 1, g);
        if (j + 1 < n && g[i][j + 1] == 1) dfs(i, j + 1, g);
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        n = grid.size();
        cnt = 1;
        int ans = 0;
        // 给岛屿领地打上编号
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j] == 1)
                {
                    ++cnt;
                    dfs(i, j, grid);
                }
            
        //若是静态数组太大 可以用 vector
        vector<int> sz(cnt + 1, 0);
        vector<bool> vis(cnt + 1, 0);

        // 统计集合面积大小
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (grid[i][j]) sz[grid[i][j]]++;

        // 枚举每个零的位置
        for (int i = 0, sum, up, left, right, down; i < n; i++)
            for (int j = 0; j < n; j++)
                if (!grid[i][j])
                {
                    //memset(vis, 0, sizeof(vis));
                    // 通过 up、left、right、down 枚举上下左右四个方向的编号
                    // 这样可以不用每次都 memset 节省时间
                    sum = 0;
                    up = i - 1 >= 0 ? grid[i - 1][j] : 0;
                    left = j - 1 >= 0 ? grid[i][j - 1] : 0;
                    right = j + 1 < n ? grid[i][j + 1] : 0;
                    down = i + 1 < n ? grid[i + 1][j] : 0;
                    if (i - 1 >= 0 && !vis[up]) 
                        sum += sz[up], vis[up] = 1;
                    if (i + 1 < n && !vis[down])
                        sum += sz[down], vis[down] = 1;
                    if (j - 1 >= 0 && !vis[left])
                        sum += sz[left], vis[left] = 1;
                    if (j + 1 < n && !vis[right])
                        sum += sz[right], vis[right] = 1;

                    vis[up]=0;
                    vis[down]=0;
                    vis[left]=0;
                    vis[right]=0;
                    ans = Max(ans, sum + 1);
                }
        return ans ? ans : n * n;
    }
};

/*
grid =
[[0,1],[0,1]]
*/
int main() {
    vector<vector<int>> grid = {{0,1},{0,1}};
    Solution s;
    cout << s.largestIsland(grid) << endl;
    return 0;
}