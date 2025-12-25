// 测试链接 : https://leetcode.cn/problems/number-of-islands/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n, m;
    void dfs(int i, int j, vector<vector<char>>& grid)
    {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0') return;
        grid[i][j] = '0';
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid); 
                    ans++;
                }
        return ans;
    }
};
/*
输入：grid = [
  ['1','1','1','1','0'],
  ['1','1','0','1','0'],
  ['1','1','0','0','0'],
  ['0','0','0','0','0']
]
*/
int main()
{
    vector<vector<char>> grid = { {'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'} };
    cout << Solution().numIslands(grid) << endl;
    return 0;
}