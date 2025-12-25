// 测试链接 : https://leetcode.cn/problems/number-of-islands/
#include <bits/stdc++.h>
using namespace std;

const int N = 310 * 310;
int n, m, f[N];
int cx[] = { 0,1,0,-1 };
int cy[] = { 1,0,-1,0 };
class Solution {
    int getIndex(int x, int y) { return x * m + y; }
    int find(int x) { return x == f[x] ? x : f[x] = find(f[x]); }

    void dfs(int x, int y, const int& fa, vector<vector<char>>& grid)
    {
        f[getIndex(x, y)] = fa;
        for (int i = 0, nx, ny, tmp; i < 4; i++)
        {
            nx = x + cx[i], ny = y + cy[i];
            tmp = getIndex(nx, ny);
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == '0' || find(tmp) != tmp || tmp == fa) continue;
            dfs(nx, ny, fa, grid);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();
        int ans = 0;
        for (int i = 0, len = n * m; i < len; i++) f[i] = i;
        for (int i = 0, tmp; i < n; i++)
            for (int j = 0; j < m; j++)
            {
                tmp = getIndex(i, j);
                if (grid[i][j] != '0' && find(tmp) == tmp)
                {
                    dfs(i, j, tmp, grid);
                    ans++;
                }
            }
        return ans;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    cout << Solution().numIslands(grid) << endl;
    return 0;
}